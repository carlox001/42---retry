#include <vector>
#include <iostream>
#include <string>


class Slide {
	public:
		std::string title;
		std::vector<std::string> bulletPoints;
		std::string imagePath;
};

class LegacyTransitionHandler {
	public:
		virtual void showSlide(const Slide& slide) {
			std::cout << "Transizione " << std::endl;
			std::cout << "Titolo: " << slide.title << "\n";
			std::cout << "Bullet:" << std::endl;
			for (const auto& bullet : slide.bulletPoints)
				std::cout << "- " << bullet << "\n";

			if (!slide.imagePath.empty())
				std::cout << "Mostra immagine: " << slide.imagePath << "\n";
		}

		virtual ~LegacyTransitionHandler() = default;
};

class LegacyPresentation {
	public:
		void present(const std::vector<Slide>& slides, LegacyTransitionHandler* handler) {
			for (const auto& slide : slides)
				handler->showSlide(slide);
		}
};

class ModernTransitionEngine: public LegacyTransitionHandler
{
	public:
		virtual void showSlideWithTransition(const Slide& slide, const Slide& next) {
			std::cout << "Titolo: " << slide.title << "\n";
			std::cout << "Bullet:" << std::endl;
			for (const auto& bullet : slide.bulletPoints)
				std::cout << "- " << bullet << "\n";

			if (!slide.imagePath.empty())
				std::cout << "Mostra immagine: " << slide.imagePath << "\n";
			if (!next.title.empty())
				std::cout << "Transizione da " << slide.title << " a " << next.title << std::endl;
		}
		virtual ~ModernTransitionEngine() = default;
};

// adapter
class TransitionAdapter : public LegacyTransitionHandler {
private:
    ModernTransitionEngine* modernHandler;
    const Slide* previousSlide = nullptr;

public:
    TransitionAdapter(ModernTransitionEngine* modern) : modernHandler(modern) {}

   void showSlide(const Slide& slide) override {
    if (previousSlide != nullptr) {
        modernHandler->showSlideWithTransition(*previousSlide, slide);
    }
    previousSlide = &slide;
}

};

int main() {
    std::vector<Slide> slides = {
        {"Slide 1", {"Punto 1", "Punto 2"}, "img1.jpg"},
        {"Slide 2", {"Altro punto"}, ""},
		{"Slide 3"}
    };

    ModernTransitionEngine transition;
    TransitionAdapter adapter(&transition);

    LegacyPresentation legacy;
    legacy.present(slides, &adapter);

    return 0;
}
