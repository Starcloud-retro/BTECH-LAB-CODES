import { EventRow } from "@/hooks/useEvents";
import { CalendarDays, MapPin, Clock, Users } from "lucide-react";
import { Button } from "@/components/ui/button";

interface EventCardProps {
  event: EventRow;
  onRegister: (event: EventRow) => void;
}

const EventCard = ({ event, onRegister }: EventCardProps) => {
  const spotsLeft = event.seats - event.registered_count;
  const fillPercent = (event.registered_count / event.seats) * 100;

  return (
    <div className="group bg-card rounded-xl overflow-hidden border border-border card-hover">
      {/* Event Image + Category Badge */}
      <div className="relative h-48 overflow-hidden">
        <img
          src={event.image_url || "/placeholder.svg"}
          alt={event.title}
          className="w-full h-full object-cover transition-transform duration-500 group-hover:scale-110"
        />
        <div className="absolute top-3 left-3">
          <span
            className={`badge-event ${
              event.category === "technical"
                ? "bg-primary text-primary-foreground"
                : event.category === "cultural"
                ? "bg-accent text-accent-foreground"
                : event.category === "sports"
                ? "bg-success text-success-foreground"
                : "bg-muted text-muted-foreground"
            }`}
          >
            {event.category}
          </span>
        </div>
      </div>

      {/* Event Details */}
      <div className="p-5 space-y-3">
        <h3 className="text-xl font-bold text-card-foreground leading-tight">
          {event.title}
        </h3>
        <p className="text-muted-foreground text-sm leading-relaxed line-clamp-2">
          {event.description}
        </p>

        {/* Date, Time, Venue */}
        <div className="space-y-1.5 text-sm text-muted-foreground">
          <div className="flex items-center gap-2">
            <CalendarDays className="w-4 h-4 text-accent" />
            <span>
              {new Date(event.date).toLocaleDateString("en-US", {
                month: "long",
                day: "numeric",
                year: "numeric",
              })}
            </span>
          </div>
          <div className="flex items-center gap-2">
            <Clock className="w-4 h-4 text-accent" />
            <span>{event.time}</span>
          </div>
          <div className="flex items-center gap-2">
            <MapPin className="w-4 h-4 text-accent" />
            <span>{event.venue}</span>
          </div>
        </div>

        {/* Seats + Progress Bar */}
        <div className="pt-2">
          <div className="flex items-center justify-between text-xs text-muted-foreground mb-1.5">
            <div className="flex items-center gap-1">
              <Users className="w-3.5 h-3.5" />
              <span>
                {event.registered_count}/{event.seats} registered
              </span>
            </div>
            <span
              className={spotsLeft <= 10 ? "text-destructive font-semibold" : ""}
            >
              {spotsLeft} spots left
            </span>
          </div>
          <div className="w-full h-1.5 bg-muted rounded-full overflow-hidden">
            <div
              className="h-full bg-accent rounded-full transition-all duration-500"
              style={{ width: `${fillPercent}%` }}
            />
          </div>
        </div>

        {/* Register Button */}
        <Button
          onClick={() => onRegister(event)}
          className="w-full mt-2"
          disabled={spotsLeft <= 0}
        >
          {spotsLeft <= 0 ? "Fully Booked" : "Register Now"}
        </Button>
      </div>
    </div>
  );
};

export default EventCard;
