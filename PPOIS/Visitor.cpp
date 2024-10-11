#include "Visitor.h"
#include <iostream>

Visitor::Visitor(const std::string& name, const Ticket& ticket)
    : name(name), ticket(ticket) {}

std::string Visitor::GetName() const {
    return name;
}

void Visitor::ViewArtwork(const Artwork& artwork) const {
    std::cout << name << " is viewing the artwork: ";
    artwork.DisplayInfo();
}

void Visitor::ShowTicket() const {
    std::cout << "Ticket Information for " << name << ":" << std::endl;
    ticket.DisplayTicketInfo();
}
