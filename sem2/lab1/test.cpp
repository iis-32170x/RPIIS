#include <iostream>
#include <cassert>
#include "queue.h"

int main() {
    setlocale(LC_ALL, "RU");
    Queue queue;

    // Тест 1: Проверка пустой очереди
    assert(queue.isEmpty());
    std::cout << "Тест 1 пройден" << std::endl;

    // Тест 2: Добавление элементов в очередь
    queue.enqueue(10);
    queue.enqueue(-20);
    queue.enqueue(30);
    std::cout << "Тест 2 пройден" << std::endl;

    // Тест 3: Проверка размера очереди
    assert(queue.size() == 3);
    std::cout << "Тест 3 пройден" << std::endl;

    // Тест 4: Проверка элемента в начале очереди
    assert(queue.front() == 10);
    std::cout << "Тест 4 пройден" << std::endl;

    // Тест 5: Извлечение элементов из очереди
    assert(queue.dequeue() == 10);
    assert(queue.dequeue() == -20);
    std::cout << "Тест 5 пройден" << std::endl;

    // Тест 6: Проверка размера очереди после извлечения
    assert(queue.size() == 1);
    std::cout << "Тест 6 пройден" << std::endl;

    // Тест 7: Проверка элемента в начале очереди после извлечения
    assert(queue.front() == 30);
    std::cout << "Тест 7 пройден" << std::endl;

    // Тест 8: Извлечение последнего элемента и проверка пустоты очереди
    assert(queue.dequeue() == 30);
    assert(queue.isEmpty());
    std::cout << "Тест 8 пройден" << std::endl;

    // Тест 9: Тест на добавление и извлечение большого количества элементов
    for (int i = 0; i < 1000; ++i) {
        queue.enqueue(i);
    }
    assert(queue.size() == 1000);
    for (int i = 0; i < 1000; ++i) {
        assert(queue.dequeue() == i);
    }
    assert(queue.isEmpty());
    std::cout << "Тест 9 пройден" << std::endl;

    // Тест 10: Тест на очистку очереди
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    assert(!queue.isEmpty());
    queue.clear();
    assert(queue.isEmpty());
    std::cout << "Тест 10 пройден" << std::endl;

    // Тест 11: Попытка извлечения элемента из пустой очереди
    assert(queue.isEmpty());
    try {
        queue.dequeue();
        // Если извлечение прошло успешно, тест не пройден
        std::cout << "Тест 11 не пройден" << std::endl;
    }
    catch (...) {
        // Если было сгенерировано исключение, то тест пройден
        std::cout << "Тест 11 пройден" << std::endl;
    }

    std::cout << "Все тесты пройдены!" << std::endl;

    return 0;
}