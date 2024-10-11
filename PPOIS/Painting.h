#pragma once
#include "Artwork.h"
#include <string>

class Painting : public Artwork {
private:
    std::string style;
public:
    Painting(const std::string& title, const std::string& artist, int year, const std::string& style);
    void DisplayInfo() const override;
};
