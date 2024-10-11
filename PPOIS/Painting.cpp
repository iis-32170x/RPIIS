#include "Painting.h"
#include <iostream>

Painting::Painting(const std::string& title, const std::string& artist, int year, const std::string& style)
    : Artwork(title, artist, year), style(style) {}

void Painting::DisplayInfo() const {
    std::cout << "Painting: " << title << " by " << artist << " (" << year << "), Style: " << style << std::endl;
}
