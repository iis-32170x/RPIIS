#pragma once
#include "Staff.h"

class Guide : public Staff {
private:
    int toursConducted; 
public:
    Guide(const std::string& name, int toursConducted);
    void Work() const override;
    void DisplayInfo() const;
};
