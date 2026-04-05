package com.satellite;

/**
 * Represents a satellite or ground station in the network.
 *
 * Each node has an orbital position angle (in degrees) that advances
 * every time step, simulating real orbital motion.
 * Ground station (node 0) has angle = 0 and does not move.
 */
public class SatelliteNode {

    public final int    id;
    public final String name;
    public final double orbitRadius;      // arbitrary units — relative distance from centre
    public       double angleDegrees;     // current position on orbit
    public final double angularSpeed;     // degrees advanced per time step
    public final boolean isGroundStation;

    public SatelliteNode(int id, String name, double orbitRadius,
                         double initialAngle, double angularSpeed,
                         boolean isGroundStation) {
        this.id             = id;
        this.name           = name;
        this.orbitRadius    = orbitRadius;
        this.angleDegrees   = initialAngle;
        this.angularSpeed   = angularSpeed;
        this.isGroundStation = isGroundStation;
    }

    /** Cartesian X position at current angle */
    public double x() {
        return orbitRadius * Math.cos(Math.toRadians(angleDegrees));
    }

    /** Cartesian Y position at current angle */
    public double y() {
        return orbitRadius * Math.sin(Math.toRadians(angleDegrees));
    }

    /** Advance orbital position by one time step */
    public void advanceOrbit() {
        if (!isGroundStation) {
            angleDegrees = (angleDegrees + angularSpeed) % 360;
        }
    }

    /** Euclidean distance to another node based on current positions */
    public double distanceTo(SatelliteNode other) {
        double dx = this.x() - other.x();
        double dy = this.y() - other.y();
        return Math.sqrt(dx * dx + dy * dy);
    }

    @Override
    public String toString() {
        return String.format("%s(%.1f°)", name, angleDegrees);
    }
}
