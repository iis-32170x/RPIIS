#pragma once
#include <string>

class Artwork {
protected:
    std::string title;
    std::string artist;
    int year;
public:
    Artwork(const std::string& title, const std::string& artist, int year);
    virtual void DisplayInfo() const =0;
    virtual ~Artwork() = default;
};
