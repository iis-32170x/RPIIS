#include "Guide.h"
#include <iostream>

Guide::Guide(const std::string& name, int toursConducted)
    : Staff(name, "Guide"), toursConducted(toursConducted) {}

void Guide::Work() const {
    std::cout << name << " is guiding a tour." << std::endl;
}

void Guide::DisplayInfo() const {
    std::cout << "Guide: " << name << ", Tours Conducted: " << toursConducted << std::endl;
}
