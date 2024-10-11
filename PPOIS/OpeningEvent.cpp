#include "OpeningEvent.h"

OpeningEvent::OpeningEvent(const std::string& eventName, const std::string& eventDate, const std::string& guestOfHonor)
    : Event(eventName, eventDate), guestOfHonor(guestOfHonor) {}

void OpeningEvent::DisplayEventDetails() const {
    std::cout << "Opening Event: " << eventName << ", Date: " << eventDate
        << ", Guest of Honor: " << guestOfHonor << std::endl;
}
