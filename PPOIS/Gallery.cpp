#include "Gallery.h"
#include <iostream>

Gallery::Gallery(const std::string& name)
    : name(name) {}

void Gallery::AddExhibition(const Exhibition& exhibition) {
    exhibitions.push_back(exhibition);
}

void Gallery::AddStaffMember(Staff* staff) {
    staffMembers.push_back(staff);
}

void Gallery::AddVisitor(const Visitor& visitor) {
    visitors.push_back(visitor);
}

void Gallery::AddEvent(Event* event) {
    events.push_back(event);
}

void Gallery::DisplayGallery() const {
    std::cout << "Gallery: " << name << std::endl;
    for (const auto& exhibition : exhibitions) {
        exhibition.DisplayExhibition();
    }
}

void Gallery::DisplayStaff() const {
    std::cout << "Staff Members:" << std::endl;
    for (const auto& staff : staffMembers) {
        staff->Work();
    }
}

void Gallery::DisplayVisitors() const {
    std::cout << "Visitors:" << std::endl;
    for (const auto& visitor : visitors) {
        std::cout << "Visitor: " << visitor.GetName() << std::endl;
        visitor.ShowTicket();
    }
}

void Gallery::DisplayEvents() const {
    std::cout << "Events:" << std::endl;
    for (const auto& event : events) {
        event->DisplayEventDetails();
    }
}
