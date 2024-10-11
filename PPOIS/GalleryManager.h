#pragma once
#include "Staff.h"

class GalleryManager : public Staff {
private:
    int yearsOfExperience; 
public:
    GalleryManager(const std::string& name, int yearsOfExperience);
    void Work() const override;
    void DisplayInfo() const;
};
