#include "Security.h"
#include <iostream>

Security::Security(const std::string& name, int postNumber)
    : Staff(name, "Security"), postNumber(postNumber) {}

void Security::Work() const {
    std::cout << name << " is securing post #" << postNumber << std::endl;
}

void Security::DisplayInfo() const {
    std::cout << "Security: " << name << ", Post Number: " << postNumber << std::endl;
}
