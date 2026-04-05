package com.satellite;

import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpExchange;

import java.io.*;
import java.net.InetSocketAddress;
import java.nio.charset.StandardCharsets;
import java.util.*;

/**
 * Minimal HTTP server — uses only Java's built-in com.sun.net.httpserver.
 * No Spring, no Maven dependencies. Just run the main() and open the browser.
 *
 * Endpoints:
 *   GET  /              → serves the simulation HTML page
 *   GET  /api/state?t=N → returns JSON state for time step N
 *   GET  /api/reset     → resets network to t=0
 */
public class SimulationServer {

    private static final int PORT = 8080;
    private static final int N    = 5;   // number of nodes

    // Shared mutable simulation state
    private static SatelliteNode[]  nodes;
    private static int[][]          edges;
    private static WeightCalculator weightCalc;
    private static String[]         names;

    // Store results per time step so step-by-step mode can replay any t
    private static final Map<Integer, String> stateCache = new HashMap<>();

    public static void main(String[] args) throws IOException {
        resetNetwork();

        HttpServer server = HttpServer.create(new InetSocketAddress(PORT), 0);

        server.createContext("/",          SimulationServer::handleRoot);
        server.createContext("/api/state", SimulationServer::handleState);
        server.createContext("/api/reset", SimulationServer::handleReset);

        server.start();
        System.out.println("=================================================");
        System.out.println("  Satellite Dijkstra Simulation");
        System.out.println("  Open browser: http://localhost:" + PORT);
        System.out.println("=================================================");
    }

    // ── Handlers ────────────────────────────────────────────────

    private static void handleRoot(HttpExchange ex) throws IOException {
        if (!ex.getRequestMethod().equals("GET")) { ex.sendResponseHeaders(405, -1); return; }
        String html = buildHTML();
        sendResponse(ex, 200, "text/html", html);
    }

    private static void handleState(HttpExchange ex) throws IOException {
        addCORS(ex);
        if (!ex.getRequestMethod().equals("GET")) { ex.sendResponseHeaders(405, -1); return; }

        String query = ex.getRequestURI().getQuery();
        int t = 0;
        if (query != null && query.startsWith("t=")) {
            try { t = Integer.parseInt(query.substring(2)); } catch (Exception ignored) {}
        }

        String json = computeState(t);
        sendResponse(ex, 200, "application/json", json);
    }

    private static void handleReset(HttpExchange ex) throws IOException {
        addCORS(ex);
        resetNetwork();
        sendResponse(ex, 200, "application/json", "{\"ok\":true}");
    }

    // ── State computation ────────────────────────────────────────

    private static String computeState(int t) {
        if (stateCache.containsKey(t)) return stateCache.get(t);

        // Rebuild network from scratch at time step t
        // (advance orbits t times from initial state)
        SatelliteNode[] freshNodes = NetworkBuilder.buildNodes();
        for (int step = 0; step < t; step++) {
            for (SatelliteNode nd : freshNodes) nd.advanceOrbit();
        }

        WeightCalculator wc = new WeightCalculator(42L + t); // deterministic per time step
        int[][] cost = wc.buildCostMatrix(freshNodes, NetworkBuilder.buildEdges(), DijkstraEngine.INF, t);

        DijkstraEngine.Result result = DijkstraEngine.run(cost, N, 1);

        // Get previous path for change detection
        List<Integer> prevPath = null;
        if (t > 0 && stateCache.containsKey(t - 1)) {
            // parse prev path from cache — simple approach: re-run t-1
            SatelliteNode[] prevNodes = NetworkBuilder.buildNodes();
            for (int step = 0; step < t - 1; step++) {
                for (SatelliteNode nd : prevNodes) nd.advanceOrbit();
            }
            WeightCalculator wc2 = new WeightCalculator(42L + (t - 1));
            int[][] prevCost = wc2.buildCostMatrix(prevNodes, NetworkBuilder.buildEdges(), DijkstraEngine.INF, t - 1);
            DijkstraEngine.Result prevResult = DijkstraEngine.run(prevCost, N, 1);
            prevPath = prevResult.path;
        }

        String json = JsonBuilder.simulationState(freshNodes, NetworkBuilder.buildEdges(),
                cost, result, t, prevPath, names, N);

        stateCache.put(t, json);
        return json;
    }

    // ── Helpers ──────────────────────────────────────────────────

    private static void resetNetwork() {
        nodes      = NetworkBuilder.buildNodes();
        edges      = NetworkBuilder.buildEdges();
        weightCalc = new WeightCalculator(42L);
        names      = NetworkBuilder.nodeNames();
        stateCache.clear();
    }

    private static void sendResponse(HttpExchange ex, int code, String type, String body) throws IOException {
        byte[] bytes = body.getBytes(StandardCharsets.UTF_8);
        ex.getResponseHeaders().set("Content-Type", type + "; charset=utf-8");
        ex.sendResponseHeaders(code, bytes.length);
        try (OutputStream os = ex.getResponseBody()) { os.write(bytes); }
    }

    private static void addCORS(HttpExchange ex) {
        ex.getResponseHeaders().set("Access-Control-Allow-Origin", "*");
    }

    // ── Inline HTML (so no static file serving needed) ───────────

    private static String buildHTML() {
        return """
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Satellite Dijkstra Simulation</title>
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body { font-family: 'Segoe UI', Arial, sans-serif; background: #0d1117; color: #e6edf3; min-height: 100vh; }

  header { background: #161b22; border-bottom: 1px solid #30363d; padding: 14px 24px; display: flex; align-items: center; gap: 16px; }
  header h1 { font-size: 17px; font-weight: 600; color: #58a6ff; }
  header span { font-size: 13px; color: #8b949e; }

  .tab-bar { display: flex; gap: 0; border-bottom: 1px solid #30363d; background: #161b22; padding: 0 24px; }
  .tab { padding: 10px 20px; font-size: 13px; cursor: pointer; border-bottom: 2px solid transparent; color: #8b949e; transition: all 0.15s; user-select: none; }
  .tab.active { color: #58a6ff; border-bottom-color: #58a6ff; }
  .tab:hover:not(.active) { color: #e6edf3; }

  .main { display: grid; grid-template-columns: 1fr 340px; gap: 0; height: calc(100vh - 90px); }
  .canvas-area { position: relative; background: #0d1117; border-right: 1px solid #30363d; }
  canvas { width: 100%; height: 100%; display: block; }

  .panel { background: #161b22; overflow-y: auto; display: flex; flex-direction: column; }
  .panel-section { padding: 16px; border-bottom: 1px solid #30363d; }
  .panel-section h3 { font-size: 12px; text-transform: uppercase; letter-spacing: 0.08em; color: #8b949e; margin-bottom: 10px; }

  .controls { display: flex; flex-direction: column; gap: 8px; }
  button { padding: 8px 14px; border-radius: 6px; border: 1px solid #30363d; font-size: 13px; cursor: pointer; transition: all 0.15s; }
  .btn-primary { background: #1f6feb; color: #fff; border-color: #1f6feb; }
  .btn-primary:hover { background: #388bfd; }
  .btn-secondary { background: #21262d; color: #e6edf3; }
  .btn-secondary:hover { background: #30363d; }
  .btn-row { display: flex; gap: 6px; }
  .btn-row button { flex: 1; }

  .time-display { font-size: 28px; font-weight: 700; color: #58a6ff; text-align: center; padding: 8px 0; }
  .time-label { font-size: 11px; color: #8b949e; text-align: center; }

  .array-table { width: 100%; border-collapse: collapse; font-size: 12px; font-family: 'Courier New', monospace; }
  .array-table th { background: #21262d; color: #8b949e; padding: 5px 8px; text-align: center; font-weight: 500; }
  .array-table td { padding: 5px 8px; text-align: center; border-top: 1px solid #21262d; }
  .array-table td.highlight { background: #1f3a5f; color: #79c0ff; font-weight: 600; }
  .array-table td.finalized { background: #1a2e1a; color: #56d364; }

  .path-display { font-family: 'Courier New', monospace; font-size: 13px; background: #21262d; border-radius: 6px; padding: 10px 12px; line-height: 1.8; }
  .path-node { color: #79c0ff; font-weight: 600; }
  .path-arrow { color: #8b949e; }
  .path-cost { color: #f0883e; font-size: 11px; }

  .changed-badge { display: inline-block; background: #3d1f00; color: #f0883e; border: 1px solid #f0883e; border-radius: 4px; font-size: 11px; padding: 2px 8px; margin-top: 6px; }

  .step-log { font-size: 12px; line-height: 1.7; }
  .step-entry { padding: 6px 0; border-bottom: 1px solid #21262d; }
  .step-entry:last-child { border-bottom: none; }
  .step-entry .iter { color: #8b949e; font-size: 11px; }
  .step-entry .selected { color: #56d364; font-weight: 600; }
  .step-entry .relaxed { color: #f0883e; font-size: 11px; }

  .weight-grid { display: grid; grid-template-columns: repeat(5, 1fr); gap: 3px; font-size: 11px; font-family: monospace; }
  .weight-cell { background: #21262d; padding: 4px; text-align: center; border-radius: 3px; }
  .weight-cell.header { color: #8b949e; font-weight: 600; }
  .weight-cell.active-path { background: #1f3a5f; color: #79c0ff; }
  .weight-cell.inf { color: #3d4450; }

  #page-time { display: none; }
  #page-step { display: none; }
  .page-active { display: flex !important; flex-direction: column; height: 100%; }
</style>
</head>
<body>

<header>
  <h1>Satellite Dijkstra Simulation</h1>
  <span>DAA Project — Adaptive Shortest Path in Dynamic Satellite Networks</span>
</header>

<div class="tab-bar">
  <div class="tab active" onclick="showTab('step')">Step-by-Step Dijkstra</div>
  <div class="tab" onclick="showTab('time')">Time Evolution</div>
</div>

<div class="main">
  <div class="canvas-area">
    <canvas id="graphCanvas"></canvas>
  </div>

  <!-- ── STEP-BY-STEP PANEL ── -->
  <div class="panel" id="page-step" style="display:flex;">

    <div class="panel-section">
      <h3>Controls — t = 0 (fixed weights)</h3>
      <div class="controls">
        <button class="btn-primary" onclick="nextStep()">▶ Next Iteration</button>
        <button class="btn-secondary" onclick="resetStep()">↺ Reset</button>
      </div>
      <div style="margin-top:10px; font-size:12px; color:#8b949e;" id="step-status">
        Initialized. Source = GND (node 1). Click Next Iteration to begin.
      </div>
    </div>

    <div class="panel-section">
      <h3>Algorithm Arrays</h3>
      <table class="array-table" id="array-table">
        <thead><tr><th>Node</th><th>GND</th><th>SAT-A</th><th>SAT-B</th><th>SAT-C</th><th>SAT-D</th></tr></thead>
        <tbody id="array-body"></tbody>
      </table>
    </div>

    <div class="panel-section" style="flex:1;">
      <h3>Iteration Log</h3>
      <div class="step-log" id="step-log"></div>
    </div>

  </div>

  <!-- ── TIME EVOLUTION PANEL ── -->
  <div class="panel" id="page-time">

    <div class="panel-section">
      <h3>Time Step</h3>
      <div class="time-display" id="time-display">t = 0</div>
      <div class="time-label">Satellites have advanced their orbits</div>
      <div class="controls" style="margin-top:12px;">
        <div class="btn-row">
          <button class="btn-secondary" onclick="prevTime()">◀ Prev</button>
          <button class="btn-primary" onclick="nextTime()">Next ▶</button>
        </div>
        <button class="btn-secondary" onclick="autoPlay()" id="autoBtn">⏵ Auto Play</button>
      </div>
    </div>

    <div class="panel-section">
      <h3>Shortest Path (GND → SAT-D)</h3>
      <div class="path-display" id="path-display">Loading...</div>
      <div id="changed-badge" style="display:none;" class="changed-badge">⚡ Path changed from previous step!</div>
    </div>

    <div class="panel-section">
      <h3>Distance Array</h3>
      <table class="array-table" id="time-array-table">
        <thead><tr><th>Node</th><th>GND</th><th>SAT-A</th><th>SAT-B</th><th>SAT-C</th><th>SAT-D</th></tr></thead>
        <tbody id="time-array-body"></tbody>
      </table>
    </div>

    <div class="panel-section" style="flex:1;">
      <h3>Edge Weights (current)</h3>
      <div id="weight-display"></div>
    </div>

  </div>
</div>

<script>
// ════════════════════════════════════════════════
//  STATE
// ════════════════════════════════════════════════
const NAMES = ["", "GND", "SAT-A", "SAT-B", "SAT-C", "SAT-D"];
const COLORS = { ground: "#f0883e", sat: "#58a6ff", pathNode: "#56d364", selected: "#ff7b72" };

let currentMode = "step";
let timeStep    = 0;
let stepIndex   = 0;
let stepData    = null;
let autoInterval = null;

// ════════════════════════════════════════════════
//  TABS
// ════════════════════════════════════════════════
function showTab(mode) {
  currentMode = mode;
  document.querySelectorAll(".tab").forEach((t, i) => {
    t.classList.toggle("active", (i === 0 && mode === "step") || (i === 1 && mode === "time"));
  });
  document.getElementById("page-step").style.display = mode === "step" ? "flex" : "none";
  document.getElementById("page-time").style.display = mode === "time" ? "flex" : "none";
  if (mode === "time") loadTimeStep(timeStep);
  if (mode === "step") { stepIndex = 0; loadStepMode(); }
}

// ════════════════════════════════════════════════
//  CANVAS
// ════════════════════════════════════════════════
const canvas = document.getElementById("graphCanvas");
const ctx    = canvas.getContext("2d");

function resizeCanvas() {
  canvas.width  = canvas.offsetWidth;
  canvas.height = canvas.offsetHeight;
}
window.addEventListener("resize", () => { resizeCanvas(); if (stepData) drawGraph(stepData, stepData.steps[stepIndex]); });
resizeCanvas();

function toCanvas(x, y, cx, cy, scale) {
  return { x: cx + x * scale, y: cy - y * scale };
}

function drawGraph(data, activeStep) {
  const w = canvas.width, h = canvas.height;
  ctx.clearRect(0, 0, w, h);

  const cx = w / 2, cy = h / 2;
  const scale = Math.min(w, h) * 0.38;

  // Determine path nodes for highlight
  const pathNodes = new Set(data.shortestPath || []);
  const pathEdges = new Set();
  const path = data.shortestPath || [];
  for (let i = 0; i < path.length - 1; i++) pathEdges.add(`${path[i]}-${path[i+1]}`);

  // Selected node in step mode
  const selectedNode = activeStep ? activeStep.selectedNode : -1;
  const relaxedEdges = new Set();
  if (activeStep) activeStep.relaxed.forEach(r => relaxedEdges.add(`${r.from}-${r.to}`));

  // Draw edges
  data.edges.forEach(e => {
    const nA = data.nodes[e.from - 1];
    const nB = data.nodes[e.to - 1];
    const pA = toCanvas(nA.x, nA.y, cx, cy, scale);
    const pB = toCanvas(nB.x, nB.y, cx, cy, scale);

    const key1 = `${e.from}-${e.to}`, key2 = `${e.to}-${e.from}`;
    const isPath    = pathEdges.has(key1) || pathEdges.has(key2);
    const isRelaxed = relaxedEdges.has(key1) || relaxedEdges.has(key2);

    ctx.beginPath();
    ctx.moveTo(pA.x, pA.y);
    ctx.lineTo(pB.x, pB.y);

    if (isPath)         { ctx.strokeStyle = "#56d364"; ctx.lineWidth = 2.5; }
    else if (isRelaxed) { ctx.strokeStyle = "#f0883e"; ctx.lineWidth = 2; }
    else                { ctx.strokeStyle = "#30363d"; ctx.lineWidth = 1; }
    ctx.stroke();

    // Weight label
    const mx = (pA.x + pB.x) / 2, my = (pA.y + pB.y) / 2;
    ctx.font = "11px Courier New";
    ctx.fillStyle = isPath ? "#56d364" : "#8b949e";
    ctx.textAlign = "center";
    ctx.fillText(e.weight, mx + 8, my - 5);
  });

  // Draw orbit rings (visual aid)
  [30, 55].forEach(r => {
    const pr = r * scale / 60;
    ctx.beginPath();
    ctx.arc(cx, cy, pr, 0, Math.PI * 2);
    ctx.strokeStyle = "#1c2128";
    ctx.lineWidth = 1;
    ctx.setLineDash([4, 6]);
    ctx.stroke();
    ctx.setLineDash([]);
  });

  // Draw nodes
  data.nodes.forEach(nd => {
    const p = toCanvas(nd.x, nd.y, cx, cy, scale);
    const r = 18;

    const isPathNode = pathNodes.has(nd.id);
    const isSelected = nd.id === selectedNode;

    // glow for selected
    if (isSelected) {
      ctx.beginPath();
      ctx.arc(p.x, p.y, r + 6, 0, Math.PI * 2);
      ctx.fillStyle = "rgba(255,123,114,0.2)";
      ctx.fill();
    }

    ctx.beginPath();
    ctx.arc(p.x, p.y, r, 0, Math.PI * 2);
    if (isSelected)       ctx.fillStyle = "#3d1f1f";
    else if (nd.isGround) ctx.fillStyle = "#2d1b00";
    else if (isPathNode)  ctx.fillStyle = "#1a2e1a";
    else                  ctx.fillStyle = "#161b22";
    ctx.fill();

    ctx.beginPath();
    ctx.arc(p.x, p.y, r, 0, Math.PI * 2);
    if (isSelected)       ctx.strokeStyle = COLORS.selected;
    else if (nd.isGround) ctx.strokeStyle = COLORS.ground;
    else if (isPathNode)  ctx.strokeStyle = COLORS.pathNode;
    else                  ctx.strokeStyle = "#30363d";
    ctx.lineWidth = isSelected || isPathNode ? 2 : 1;
    ctx.stroke();

    // Node label
    ctx.font = "bold 10px Segoe UI";
    ctx.textAlign = "center";
    ctx.textBaseline = "middle";
    ctx.fillStyle = isSelected ? COLORS.selected : (nd.isGround ? COLORS.ground : (isPathNode ? COLORS.pathNode : "#8b949e"));
    ctx.fillText(nd.name, p.x, p.y);
  });
}

// ════════════════════════════════════════════════
//  STEP-BY-STEP MODE
// ════════════════════════════════════════════════
async function loadStepMode() {
  const data = await fetch("/api/state?t=0").then(r => r.json());
  stepData = data;
  renderStepState();
}

function renderStepState() {
  const step = stepData.steps[stepIndex];
  drawGraph(stepData, step);
  renderArrayTable(step, "array-body");
  renderStepLog();
  updateStepStatus(step);
}

function renderArrayTable(step, bodyId) {
  const body = document.getElementById(bodyId);
  const finalizedSet = new Set();
  for (let s = 0; s <= stepIndex; s++) {
    finalizedSet.add(stepData.steps[s].selectedNode);
  }

  const rows = [
    { label: "dist[]", values: step.distance },
    { label: "pred[]", values: step.pred, isNames: true }
  ];
  body.innerHTML = rows.map(row =>
    `<tr><td style="color:#8b949e;text-align:left;padding-left:8px">${row.label}</td>` +
    step.distance.map((_, i) => {
      const v = row.values[i];
      const display = row.isNames ? NAMES[v] : (v === 999 ? "∞" : v);
      const cls = finalizedSet.has(i + 1) ? "finalized" : (i + 1 === step.selectedNode ? "highlight" : "");
      return `<td class="${cls}">${display}</td>`;
    }).join("") +
    "</tr>"
  ).join("");
}

function renderStepLog() {
  const log = document.getElementById("step-log");
  log.innerHTML = stepData.steps.slice(0, stepIndex + 1).map((s, i) => {
    if (i === 0) return `<div class="step-entry"><span class="iter">Init</span><br>Source = GND, dist initialized from direct edges.</div>`;
    const relaxedStr = s.relaxed.length
      ? s.relaxed.map(r => `${NAMES[r.to]}: ${r.oldDist === 999 ? "∞" : r.oldDist} → ${r.newDist}`).join(", ")
      : "No improvements found.";
    return `<div class="step-entry">
      <span class="iter">Iter ${s.iteration}</span><br>
      Selected: <span class="selected">${s.selectedName}</span> (dist = ${stepData.distance[s.selectedNode]})<br>
      <span class="relaxed">Updated: ${relaxedStr}</span>
    </div>`;
  }).reverse().join("");
}

function updateStepStatus(step) {
  const el = document.getElementById("step-status");
  if (stepIndex === 0) { el.textContent = "Initialized. Click Next Iteration."; return; }
  const done = stepIndex >= stepData.steps.length - 1;
  el.textContent = done
    ? "Algorithm complete. All nodes finalized."
    : `Iter ${step.iteration}: Selected ${step.selectedName}. ${stepData.steps.length - 1 - stepIndex} iterations remaining.`;
}

function nextStep() {
  if (!stepData) { loadStepMode(); return; }
  if (stepIndex < stepData.steps.length - 1) { stepIndex++; renderStepState(); }
}

function resetStep() { stepIndex = 0; if (stepData) renderStepState(); }

// ════════════════════════════════════════════════
//  TIME EVOLUTION MODE
// ════════════════════════════════════════════════
async function loadTimeStep(t) {
  timeStep = t;
  const data = await fetch(`/api/state?t=${t}`).then(r => r.json());
  stepData = data;

  document.getElementById("time-display").textContent = `t = ${t}`;
  drawGraph(data, null);
  renderTimePanel(data);
}

function renderTimePanel(data) {
  // path display
  const pathEl = document.getElementById("path-display");
  const path   = data.shortestPath;
  const totalCost = data.distance[data.distance.length - 1];
  pathEl.innerHTML = path.map(n => `<span class="path-node">${NAMES[n]}</span>`).join(' <span class="path-arrow">→</span> ')
    + `<br><span class="path-cost">Total cost: ${totalCost}</span>`;

  // changed badge
  document.getElementById("changed-badge").style.display = data.pathChanged ? "block" : "none";

  // distance array
  const body = document.getElementById("time-array-body");
  const pathSet = new Set(data.shortestPath);
  body.innerHTML =
    `<tr><td style="color:#8b949e;text-align:left;padding-left:8px">dist[]</td>` +
    data.distance.map((d, i) => {
      const cls = pathSet.has(i + 1) ? "highlight" : "";
      return `<td class="${cls}">${d === 999 ? "∞" : d}</td>`;
    }).join("") + "</tr>" +
    `<tr><td style="color:#8b949e;text-align:left;padding-left:8px">pred[]</td>` +
    data.pred.map(p => `<td>${NAMES[p]}</td>`).join("") + "</tr>";

  // edge weights
  const edgeEl = document.getElementById("weight-display");
  edgeEl.innerHTML = data.edges.map(e => {
    const isPath = data.shortestPath.some((n, i) =>
      i < data.shortestPath.length - 1 &&
      ((n === e.from && data.shortestPath[i+1] === e.to) ||
       (n === e.to && data.shortestPath[i+1] === e.from)));
    return `<div style="display:flex;justify-content:space-between;font-size:12px;font-family:monospace;padding:3px 0;border-bottom:1px solid #21262d">
      <span style="color:${isPath ? '#56d364' : '#8b949e'}">${NAMES[e.from]} → ${NAMES[e.to]}</span>
      <span style="color:${isPath ? '#56d364' : '#e6edf3'}">${e.weight}</span>
    </div>`;
  }).join("");
}

function nextTime() { if (autoInterval) stopAuto(); loadTimeStep(timeStep + 1); }
function prevTime() { if (timeStep > 0) { if (autoInterval) stopAuto(); loadTimeStep(timeStep - 1); } }

function autoPlay() {
  if (autoInterval) { stopAuto(); return; }
  document.getElementById("autoBtn").textContent = "⏸ Pause";
  autoInterval = setInterval(() => {
    if (timeStep >= 20) { stopAuto(); return; }
    loadTimeStep(timeStep + 1);
  }, 1200);
}

function stopAuto() {
  clearInterval(autoInterval);
  autoInterval = null;
  document.getElementById("autoBtn").textContent = "⏵ Auto Play";
}

// ════════════════════════════════════════════════
//  INIT
// ════════════════════════════════════════════════
loadStepMode();
</script>
</body>
</html>
""";
    }
}
