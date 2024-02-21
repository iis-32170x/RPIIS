// DualLinkedListLibrary.cpp : Определяет функции для статической библиотеки.
//DualLinkedListLibrary.cpp

#include "pch.h"
#include "framework.h"
#include <iostream>
#include "DLLLibrary.h"

namespace DLLLibrary
{
    //Создать пустой двусвязный список (конструктор класса)
    LinkedList::LinkedList() {
        head = nullptr;
        tail = nullptr;
        elementCount = 0;
    }

    // Метод (функция), возвращающая кол-во элеменетов в списке
    int LinkedList::GetSize() const {
        return elementCount;
    }

    // Метод (функция), проверяющая, является ли список пустым
    bool LinkedList::CheckEmpty() const {
        return elementCount == 0;
    }

    //Вставить (создать) узел в начало списка
    void LinkedList::pushFront(int value) {
        Node* newNode = new Node(value, head, nullptr);
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        elementCount++;
    }

    //Вставить (создать) узел в конец списка
    void LinkedList::pushBack(int value) {
        Node* newNode = new Node(value, nullptr, tail);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        elementCount++;
    }

    //Удалить узел в начале списка
    void LinkedList::popFront() {
        if (head != nullptr) {
            Node* oldHead = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete oldHead;
            elementCount--;
        }
    }

    //Удалить узел в конце списка
    void LinkedList::popBack() {
        if (tail != nullptr) {
            Node* oldTail = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            delete oldTail;
            elementCount--;
        }
    }

    //Деструктор списка
    LinkedList::~LinkedList() {
        while (!CheckEmpty()) {
            popFront();
        }
    }

    //Метод (функция) получения адреса узла по индексу
    Node* LinkedList::getNode(int index) {
        Node* n = head;
        for (int i = 0; i < index && n != nullptr; i++) {
            n = n->next;
        }
        return n;
    }

    // Метод получения значения по индексу
    int LinkedList::getValue(int index) {
        Node* node = getNode(index);
        if (node != nullptr) {
            return node->value;
        }
    }

    //Вставка узла (создание) после заданного узла
    void LinkedList::insertAfter(Node* elem, int value) {
        if (elem == tail) {
            pushBack(value);
        }
        else {
            Node* n = new Node(value, elem->next, elem);
            elem->next->prev = n;
            elem->next = n;
            elementCount++;
        }
    }


    //Вставка узла (создание) перед заданным узлом
    void LinkedList::insertBefore(Node* elem, int value) {
        if (elem == head) {
            pushFront(value);
        }
        else {
            Node* n = new Node(value, elem, elem->prev);
            elem->prev->next = n;
            elem->prev = n;
            elementCount++;
        }
    }

    //Удаление узла из середины
    void LinkedList::erase(Node* elem) {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        delete elem;
        elementCount--;
    }

    //Вывести список в консоль
    void LinkedList::print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Метод получения значения первого элемента
    int LinkedList::getFront() const {
        return head->value;
    }

    // Метод получения значения второго элемента
    int LinkedList::getBack() const {
        return tail->value;
    };

    // Метод сортировки списка (пузырьком)
    void LinkedList::Sort() {
        if (CheckEmpty()) {
            return;
        }
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->value > current->next->value) {
                    std::swap(current->value, current->next->value);
                    sorted = false;
                }
                current = current->next;
            }
        }
    }

    // Метод объединения двух списков
    LinkedList LinkedList::merge(LinkedList& otherList) const {
        LinkedList mergedList;
        Node* currentOther = otherList.head;
        Node* currentThis = head;

        // Первый список
        while (currentThis != nullptr) {
            mergedList.pushBack(currentThis->value);
            currentThis = currentThis->next;
        }
        
        // Второй список
        while (currentOther != nullptr) {
            mergedList.pushBack(currentOther->value);
            currentOther = currentOther->next;
        }

        return mergedList;
    }

    //Метод пересечения двух списков
    LinkedList LinkedList::intersection(LinkedList& otherList) const {
        LinkedList intersectedList;

        Node* currentOther = otherList.head;
        while (currentOther != nullptr) {
            Node* currentThis = head;
            while (currentThis != nullptr) {
                if (currentThis->value == currentOther->value) {
                    intersectedList.pushBack(currentThis->value);
                    break;
                }
                currentThis = currentThis->next;
            }
            currentOther = currentOther->next;
        }

        return intersectedList;
    }
}
    

    
    


    


