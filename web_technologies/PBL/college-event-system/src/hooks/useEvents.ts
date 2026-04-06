import { useQuery } from "@tanstack/react-query";
import { supabase } from "@/integrations/supabase/client";
import type { Tables } from "@/integrations/supabase/types";

export type EventRow = Tables<"events">;

export const useEvents = (category?: string) => {
  return useQuery({
    queryKey: ["events", category],
    queryFn: async () => {
      let query = supabase
        .from("events")
        .select("*")
        .order("date", { ascending: true });

      if (category && category !== "all") {
        query = query.eq("category", category);
      }

      const { data, error } = await query;
      if (error) throw error;

      return data as EventRow[];
    },
  });
};
