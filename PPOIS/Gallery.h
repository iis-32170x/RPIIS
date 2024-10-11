#pragma once
#include <string>
#include <vector>
#include "Exhibition.h"
#include "Staff.h"
#include "Visitor.h"
#include "Event.h"  

class Gallery {
private:
    std::string name;
    std::vector<Exhibition> exhibitions;
    std::vector<Staff*> staffMembers;
    std::vector<Visitor> visitors;
    std::vector<Event*> events;
public:
    Gallery(const std::string& name);
    void AddExhibition(const Exhibition& exhibition);
    void AddStaffMember(Staff* staff);
    void AddVisitor(const Visitor& visitor);
    void AddEvent(Event* event);
    void DisplayGallery() const;
    void DisplayStaff() const;
    void DisplayVisitors() const;
    void DisplayEvents() const;
};