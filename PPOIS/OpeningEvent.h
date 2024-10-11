#pragma once
#include "Event.h"
#include <string>

class OpeningEvent : public Event {
private:
    std::string guestOfHonor;  // Почетный гость
public:
    OpeningEvent(const std::string& eventName, const std::string& eventDate, const std::string& guestOfHonor);
    void DisplayEventDetails() const override;
};
