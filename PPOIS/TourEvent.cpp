#include "TourEvent.h"

TourEvent::TourEvent(const std::string& eventName, const std::string& eventDate, const std::string& tourGuide)
    : Event(eventName, eventDate), tourGuide(tourGuide) {}

void TourEvent::DisplayEventDetails() const {
    std::cout << "Tour Event: " << eventName << ", Date: " << eventDate
        << ", Tour Guide: " << tourGuide << std::endl;
}
