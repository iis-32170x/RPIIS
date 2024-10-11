#pragma once
#include <string>

class Staff {
protected:
    std::string name;
    std::string role;
public:
    Staff(const std::string& name, const std::string& role);
    virtual void Work() const = 0;
    virtual ~Staff() = default;
};
