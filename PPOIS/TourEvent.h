#pragma once
#include "Event.h"
#include <string>

class TourEvent : public Event {
private:
    std::string tourGuide;  // Ёкскурсовод
public:
    TourEvent(const std::string& eventName, const std::string& eventDate, const std::string& tourGuide);
    void DisplayEventDetails() const override;
};
