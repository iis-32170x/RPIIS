#include "GalleryManager.h"
#include <iostream>

GalleryManager::GalleryManager(const std::string& name, int yearsOfExperience)
    : Staff(name, "Gallery Manager"), yearsOfExperience(yearsOfExperience) {}

void GalleryManager::Work() const {
    std::cout << name << " is managing the gallery with " << yearsOfExperience << " years of experience." << std::endl;
}

void GalleryManager::DisplayInfo() const {
    std::cout << "Gallery Manager: " << name << ", Years of Experience: " << yearsOfExperience << std::endl;
}
