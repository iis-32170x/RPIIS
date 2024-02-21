//DLLLibrary.h
#pragma once
namespace DLLLibrary
{ // Структура узла из трёх полей
    struct Node {
        int value;
        Node* next;
        Node* prev;

        // Конструктор узлов
        Node(int v, Node* n, Node* p) {
            value = v;
            next = n;
            prev = p;
        }
    };

    // Класс двунаправленного связного списка
	class LinkedList {

    private:
        Node* head;
        Node* tail;
        int elementCount;

    public:
        //Создать пустой двусвязный список
        LinkedList();

        //Деструктор списка
        ~LinkedList();

        // Сортировка списка (пузырьком)
        void Sort();

        //Метод (функция) получения индекса узла
        Node* getNode(int index);

        //Метод для объединения двух списков
        LinkedList merge(LinkedList& otherList) const;

        //Метод для пересечения двух списков
        LinkedList intersection(LinkedList& otherList) const;

        // Оператор 
        int getValue (int index);

        // Метод (функция), возвращающая кол-во элеменетов в списке
        int GetSize() const;

        // Метод (функция), проверяющая, является ли список пустым
        bool CheckEmpty() const;

        //Вставка узла (создание) после заданного узла
        void insertAfter(Node* elem, int value);

        //Вставка узла (создание) перед заданным узлом
        void insertBefore(Node* elem, int value);

        //Удаление узла
        void erase(Node* elem);

        //Вставить (создать) узел в начало списка
        void pushFront(int value);

        //Удалить узел в начале списка
        void popFront();

        //Удалить узел в конце списка
        void popBack();

        //Вставить (создать) узел в конец списка
        void pushBack(int value);

        //Вывести список в консоль
        void print() const;

        //Получить значение первого узла
        int getFront() const;
        
        //Получить значение последнего узла
        int getBack() const;
	};
}