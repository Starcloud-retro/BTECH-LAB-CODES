import { GraduationCap, ArrowDown } from "lucide-react";

const HeroSection = () => {
  return (
    <section className="hero-gradient min-h-[420px] flex flex-col items-center justify-center text-center px-6 py-20 relative overflow-hidden">
      {/* Decorative Background */}
      <div className="absolute inset-0 opacity-10">
        <div className="absolute top-10 left-10 w-72 h-72 bg-accent rounded-full blur-3xl" />
        <div className="absolute bottom-10 right-10 w-96 h-96 bg-primary-foreground rounded-full blur-3xl" />
      </div>

      {/* Content */}
      <div className="relative z-10 max-w-3xl mx-auto space-y-6">
        {/* Semester Badge */}
        <div className="inline-flex items-center gap-2 bg-primary-foreground/10 backdrop-blur-sm border border-primary-foreground/20 rounded-full px-4 py-1.5 text-sm text-primary-foreground/90">
          <GraduationCap className="w-4 h-4" />
          <span>Spring Semester 2026</span>
        </div>

        {/* Title */}
        <h1 className="text-4xl md:text-6xl font-extrabold text-primary-foreground leading-tight tracking-tight">
          Campus Events
        </h1>

        {/* Subtitle */}
        <p className="text-lg md:text-xl text-primary-foreground/75 max-w-xl mx-auto leading-relaxed">
          Discover, register, and participate in the best events happening across campus.
        </p>

        {/* CTA */}
        <a
          href="#events"
          className="inline-flex items-center gap-2 text-primary-foreground/80 hover:text-primary-foreground transition-colors text-sm mt-4"
        >
          Browse Events <ArrowDown className="w-4 h-4 animate-bounce" />
        </a>
      </div>
    </section>
  );
};

export default HeroSection;
