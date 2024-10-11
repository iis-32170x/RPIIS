#pragma once
#include "Artwork.h"
#include <string>

class Sculpture : public Artwork {
private:
    std::string material;
public:
    Sculpture(const std::string& title, const std::string& artist, int year, const std::string& material);
    void DisplayInfo() const override;
};
