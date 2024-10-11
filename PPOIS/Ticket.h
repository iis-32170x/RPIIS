#pragma once

class Ticket {
private:
    int price;   // Цена билета
    int number;  // Номер билета
public:
    Ticket(int price, int number);
    void DisplayTicketInfo() const;
    int GetNumber() const;
};
