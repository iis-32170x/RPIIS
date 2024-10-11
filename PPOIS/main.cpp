#include <iostream>
#include "Gallery.h"
#include "Guide.h"
#include "Security.h"
#include "GalleryManager.h"
#include "Painting.h"
#include "Sculpture.h"
#include "Ticket.h"
#include "Visitor.h"
#include "OpeningEvent.h"
#include "TourEvent.h"

int main() {
    // Создание галереи
    Gallery gallery("National Art Gallery");

    // Создание выставки
    Exhibition exhibition("Impressionist Paintings");

    // Добавление картин
    Painting painting1("Starry Night", "Vincent van Gogh", 1889, "Post-Impressionism");
    Sculpture sculpture1("David", "Michelangelo", 1504, "Marble");

    exhibition.AddArtwork(&painting1);
    exhibition.AddArtwork(&sculpture1);
    gallery.AddExhibition(exhibition);

    // Добавление сотрудников
    Guide guide("Alice", 50);  
    Security security("Bob", 3);  
    GalleryManager manager("Clara", 10);  

    gallery.AddStaffMember(&guide);
    gallery.AddStaffMember(&security);
    gallery.AddStaffMember(&manager);

    // Добавление посетителей с билетами
    Ticket ticket1(20, 1001);  
    Visitor visitor1("John Doe", ticket1);
    gallery.AddVisitor(visitor1);

    // Создание и добавление событий
    OpeningEvent opening("Grand Opening", "2024-10-01", "Leonardo DiCaprio");
    TourEvent tour("Gallery Tour", "2024-10-02", "Alice");

    gallery.AddEvent(&opening);
    gallery.AddEvent(&tour);

    // Вывод информации о галерее, сотрудниках, посетителях и событиях
    gallery.DisplayGallery();
    gallery.DisplayStaff();
    gallery.DisplayVisitors();
    gallery.DisplayEvents();

    return 0;
}

