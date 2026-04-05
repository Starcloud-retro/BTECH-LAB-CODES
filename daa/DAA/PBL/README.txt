SATELLITE DIJKSTRA SIMULATION
==============================
DAA Project — Adaptive Shortest Path in Dynamic Satellite Networks
Team: Metri Naveen Kumar, Sahit Kumar Yadav, Shaik Zaheer Abbas

HOW TO RUN
----------
Requires Java 11 or above.

  java -jar satellite-sim.jar

Then open your browser at:  http://localhost:8080

WHAT IT SHOWS
-------------
Tab 1 — Step-by-Step Dijkstra
  Click "Next Iteration" to walk through the algorithm.
  See distance[] and pred[] arrays update live.
  Finalized nodes shown in green.

Tab 2 — Time Evolution
  Click "Next" to advance time steps.
  Satellites move. Weights change.
  When the optimal path changes, an alert appears.
  Use "Auto Play" to watch it run continuously.

PROJECT STRUCTURE (source files)
---------------------------------
SatelliteNode.java    — orbital position + motion model
WeightCalculator.java — 3-term weight formula (distance + delay + interference)
NetworkBuilder.java   — 5-node network definition
DijkstraEngine.java   — Dijkstra's algorithm (mam's exact logic + step trace)
JsonBuilder.java      — JSON serializer (no external libraries)
SimulationServer.java — HTTP server + HTML frontend (no Spring, no Maven)
