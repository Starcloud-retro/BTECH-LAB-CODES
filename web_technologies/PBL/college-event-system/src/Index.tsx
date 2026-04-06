import { useState } from "react";
import { useNavigate } from "react-router-dom";
import { LogOut } from "lucide-react";

import HeroSection from "@/components/HeroSection";
import EventCard from "@/components/EventCard";
import RegistrationModal from "@/components/RegistrationModal";
import { Button } from "@/components/ui/button";
import { useEvents, EventRow } from "@/hooks/useEvents";
import { useAuth } from "@/hooks/useAuth";

const categories = ["all", "technical", "cultural", "sports", "workshop"] as const;

const Index = () => {
  const [filter, setFilter] = useState<string>("all");
  const [selectedEvent, setSelectedEvent] = useState<EventRow | null>(null);
  const [modalOpen, setModalOpen] = useState(false);

  const { data: events, isLoading } = useEvents(filter);
  const { user, signOut } = useAuth();
  const navigate = useNavigate();

  const handleRegister = (event: EventRow) => {
    if (!user) {
      navigate("/auth");
      return;
    }
    setSelectedEvent(event);
    setModalOpen(true);
  };

  return (
    <div className="min-h-screen bg-background">
      {/* Auth Button */}
      <div className="absolute top-4 right-4 z-20">
        {user ? (
          <Button
            variant="outline"
            size="sm"
            onClick={signOut}
            className="gap-2 bg-card/80 backdrop-blur-sm"
          >
            <LogOut className="w-4 h-4" /> Sign Out
          </Button>
        ) : (
          <Button
            size="sm"
            onClick={() => navigate("/auth")}
            className="bg-card/80 backdrop-blur-sm text-foreground hover:bg-card"
          >
            Sign In
          </Button>
        )}
      </div>

      {/* Hero Section */}
      <HeroSection />

      {/* Events Section */}
      <main id="events" className="max-w-6xl mx-auto px-4 sm:px-6 py-12">
        {/* Category Filter */}
        <div className="flex flex-wrap items-center gap-2 mb-8">
          {categories.map((cat) => (
            <button
              key={cat}
              onClick={() => setFilter(cat)}
              className={`badge-event transition-colors ${
                filter === cat
                  ? "bg-primary text-primary-foreground"
                  : "bg-secondary text-secondary-foreground hover:bg-muted"
              }`}
            >
              {cat}
            </button>
          ))}
        </div>

        {/* Events Grid */}
        {isLoading ? (
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
            {[1, 2, 3].map((i) => (
              <div key={i} className="h-96 bg-muted animate-pulse rounded-xl" />
            ))}
          </div>
        ) : (
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6">
            {events?.map((event) => (
              <EventCard key={event.id} event={event} onRegister={handleRegister} />
            ))}
          </div>
        )}

        {/* Empty State */}
        {!isLoading && events?.length === 0 && (
          <p className="text-center text-muted-foreground py-16">
            No events in this category yet.
          </p>
        )}
      </main>

      {/* Footer */}
      <footer className="border-t border-border py-6 text-center text-sm text-muted-foreground">
        © 2026 College Event Registration System
      </footer>

      {/* Registration Modal */}
      <RegistrationModal
        event={selectedEvent}
        open={modalOpen}
        onClose={() => setModalOpen(false)}
      />
    </div>
  );
};

export default Index;
