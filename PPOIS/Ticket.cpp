#include "Ticket.h"
#include <iostream>

Ticket::Ticket(int price, int number)
    : price(price), number(number) {}

void Ticket::DisplayTicketInfo() const {
    std::cout << "Ticket Number: " << number << ", Price: $" << price << std::endl;
}

int Ticket::GetNumber() const {
    return number;
}
