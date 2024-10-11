#include "Sculpture.h"
#include <iostream>

Sculpture::Sculpture(const std::string& title, const std::string& artist, int year, const std::string& material)
    : Artwork(title, artist, year), material(material) {}

void Sculpture::DisplayInfo() const {
    std::cout << "Sculpture: " << title << " by " << artist << " (" << year << "), Material: " << material << std::endl;
}
