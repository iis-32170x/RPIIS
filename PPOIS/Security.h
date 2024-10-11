#pragma once
#include "Staff.h"

class Security : public Staff {
private:
    int postNumber; // Номер охранного поста
public:
    Security(const std::string& name, int postNumber);
    void Work() const override;
    void DisplayInfo() const;
};
