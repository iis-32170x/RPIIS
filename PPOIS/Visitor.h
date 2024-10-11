#pragma once
#include <string>
#include "Ticket.h"
#include "Artwork.h"

class Visitor {
private:
    std::string name;  // ��� ����������
    Ticket ticket;     // �����, ������������� ����������
public:
    Visitor(const std::string& name, const Ticket& ticket);
    std::string GetName() const;
    void ViewArtwork(const Artwork& artwork) const;
    void ShowTicket() const;  // �������� �����
};
