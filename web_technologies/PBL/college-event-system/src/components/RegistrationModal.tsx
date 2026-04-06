import { useState } from "react";
import { useQueryClient } from "@tanstack/react-query";
import { CheckCircle } from "lucide-react";

import { EventRow } from "@/hooks/useEvents";
import { supabase } from "@/integrations/supabase/client";
import { useAuth } from "@/hooks/useAuth";
import { useToast } from "@/hooks/use-toast";

import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogDescription,
} from "@/components/ui/dialog";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Button } from "@/components/ui/button";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";

interface RegistrationModalProps {
  event: EventRow | null;
  open: boolean;
  onClose: () => void;
}

const RegistrationModal = ({ event, open, onClose }: RegistrationModalProps) => {
  const { toast } = useToast();
  const { user } = useAuth();
  const queryClient = useQueryClient();

  const [submitted, setSubmitted] = useState(false);
  const [loading, setLoading] = useState(false);
  const [form, setForm] = useState({
    name: "",
    email: "",
    phone: "",
    department: "",
    year: "",
  });

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    if (!form.name || !form.email || !form.department || !form.year) {
      toast({
        title: "Missing fields",
        description: "Please fill all required fields.",
        variant: "destructive",
      });
      return;
    }
    if (!user || !event) return;

    setLoading(true);
    try {
      const { error } = await supabase.from("registrations").insert({
        event_id: event.id,
        user_id: user.id,
        name: form.name.trim(),
        email: form.email.trim(),
        phone: form.phone.trim() || null,
        department: form.department,
        year: form.year,
      });

      if (error) {
        if (error.code === "23505") {
          toast({
            title: "Already registered",
            description: "You've already registered for this event.",
            variant: "destructive",
          });
        } else {
          throw error;
        }
      } else {
        setSubmitted(true);
        queryClient.invalidateQueries({ queryKey: ["events"] });
        toast({
          title: "Registration Successful!",
          description: `You've registered for ${event.title}.`,
        });
      }
    } catch (error: any) {
      toast({
        title: "Error",
        description: error.message,
        variant: "destructive",
      });
    } finally {
      setLoading(false);
    }
  };

  const handleClose = () => {
    setSubmitted(false);
    setForm({ name: "", email: "", phone: "", department: "", year: "" });
    onClose();
  };

  if (!event) return null;

  return (
    <Dialog open={open} onOpenChange={handleClose}>
      <DialogContent className="sm:max-w-md">
        {submitted ? (
          <div className="flex flex-col items-center py-8 gap-4 text-center">
            <div className="w-16 h-16 rounded-full bg-success/10 flex items-center justify-center">
              <CheckCircle className="w-8 h-8 text-success" />
            </div>
            <DialogTitle className="text-2xl">You're In!</DialogTitle>
            <p className="text-muted-foreground">
              Successfully registered for <strong>{event.title}</strong>.
            </p>
            <Button onClick={handleClose} className="mt-2">
              Done
            </Button>
          </div>
        ) : (
          <>
            <DialogHeader>
              <DialogTitle className="text-xl">
                Register for {event.title}
              </DialogTitle>
              <DialogDescription>
                Fill in your details to secure your spot.
              </DialogDescription>
            </DialogHeader>

            <form onSubmit={handleSubmit} className="space-y-4 mt-2">
              <div className="space-y-1.5">
                <Label htmlFor="name">Full Name *</Label>
                <Input
                  id="name"
                  value={form.name}
                  onChange={(e) => setForm({ ...form, name: e.target.value })}
                  placeholder="John Doe"
                  maxLength={100}
                />
              </div>

              <div className="space-y-1.5">
                <Label htmlFor="email">Email *</Label>
                <Input
                  id="email"
                  type="email"
                  value={form.email}
                  onChange={(e) => setForm({ ...form, email: e.target.value })}
                  placeholder="john@college.edu"
                  maxLength={255}
                />
              </div>

              <div className="space-y-1.5">
                <Label htmlFor="phone">Phone</Label>
                <Input
                  id="phone"
                  type="tel"
                  value={form.phone}
                  onChange={(e) => setForm({ ...form, phone: e.target.value })}
                  placeholder="+91 9876543210"
                  maxLength={15}
                />
              </div>

              <div className="grid grid-cols-2 gap-3">
                <div className="space-y-1.5">
                  <Label>Department *</Label>
                  <Select
                    onValueChange={(v) =>
                      setForm({ ...form, department: v })
                    }
                  >
                    <SelectTrigger>
                      <SelectValue placeholder="Select" />
                    </SelectTrigger>
                    <SelectContent>
                      <SelectItem value="cse">CSE</SelectItem>
                      <SelectItem value="ece">ECE</SelectItem>
                      <SelectItem value="eee">EEE</SelectItem>
                      <SelectItem value="mech">MECH</SelectItem>
                      <SelectItem value="civil">CIVIL</SelectItem>
                      <SelectItem value="it">IT</SelectItem>
                    </SelectContent>
                  </Select>
                </div>

                <div className="space-y-1.5">
                  <Label>Year *</Label>
                  <Select
                    onValueChange={(v) => setForm({ ...form, year: v })}
                  >
                    <SelectTrigger>
                      <SelectValue placeholder="Select" />
                    </SelectTrigger>
                    <SelectContent>
                      <SelectItem value="1">1st Year</SelectItem>
                      <SelectItem value="2">2nd Year</SelectItem>
                      <SelectItem value="3">3rd Year</SelectItem>
                      <SelectItem value="4">4th Year</SelectItem>
                    </SelectContent>
                  </Select>
                </div>
              </div>

              <Button type="submit" className="w-full" disabled={loading}>
                {loading ? "Registering..." : "Confirm Registration"}
              </Button>
            </form>
          </>
        )}
      </DialogContent>
    </Dialog>
  );
};

export default RegistrationModal;
