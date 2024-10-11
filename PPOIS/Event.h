#pragma once
#include <string>
#include <iostream>

class Event {
protected:
    std::string eventName;
    std::string eventDate;  // ���� ���������� �������
public:
    Event(const std::string& eventName, const std::string& eventDate);
    virtual void DisplayEventDetails() const =0 ;
    virtual ~Event() = default;
};
