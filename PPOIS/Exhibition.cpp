#include "Exhibition.h"
#include <iostream>

Exhibition::Exhibition(const std::string& title)
    : title(title) {}

void Exhibition::AddArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

void Exhibition::DisplayExhibition() const {
    std::cout << "Exhibition: " << title << std::endl;
    for (const auto& artwork : artworks) {
        artwork->DisplayInfo();
    }
}
