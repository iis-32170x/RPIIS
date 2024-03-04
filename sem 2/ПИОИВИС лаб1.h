#pragma once
using namespace std;


class MyQueue {
public:
    MyQueue(); // Конструктор
    virtual ~MyQueue(); // Деструктор

    void Push(string information); // Добавление элемента в очередь
    string Pop(); // Извлечение элемента из очереди
    void View(); // Просмотр очереди
    bool Check(); // Проверка на пустоту очереди
    void HeadElemenetToTail(); // Перемещение элемента из головы в хвост

private:
    typedef struct QueueElement {
        string inf; // Информация о элементе
        QueueElement* prev; // Указатель на предыдущий элемент
    } QueueElement;

    QueueElement* last; // Указатель на последний элемент очереди
    QueueElement* begin; // Указатель на первый элемент очереди
};
