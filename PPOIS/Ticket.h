#pragma once

class Ticket {
private:
    int price;   // ���� ������
    int number;  // ����� ������
public:
    Ticket(int price, int number);
    void DisplayTicketInfo() const;
    int GetNumber() const;
};
