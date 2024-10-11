#pragma once
#include <string>
#include <vector>
#include "Artwork.h"

class Exhibition {
private:
    std::string title;
    std::vector<Artwork*> artworks;
public:
    Exhibition(const std::string& title);
    void AddArtwork(Artwork* artwork);
    void DisplayExhibition() const;
};
