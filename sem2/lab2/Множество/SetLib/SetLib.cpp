// SetLib.cpp : Определяет функции для статической библиотеки.
//

#include "..\SetLib\Header.h"
#include "pch.h"
#include "framework.h"
#include <iostream>
#include <vector>

namespace SetLib
{
    std::vector<std::vector<int>> cartesianProduct(const std::vector<std::vector<int>>& sets) {
        // Если вектор множеств пуст, возвращаем вектор с одним пустым множеством
        if (sets.empty()) {
            return { {} };
        }

        // Рекурсивно находим декартово произведение всех множеств, кроме первого
        auto tailCartesian = cartesianProduct(std::vector<std::vector<int>>(sets.begin() + 1, sets.end()));

        // Результирующий вектор декартова произведения
        std::vector<std::vector<int>> result;

        // Перебираем все элементы первого множества
        for (const auto& element : sets[0]) {
            // Для каждого элемента первого множества объединяем его с элементами декартова произведения остальных множеств
            for (const auto& tail : tailCartesian) {
                // Формируем новое множество, объединяя элемент из первого множества с элементами из декартова произведения
                std::vector<int> newSet = { element };
                newSet.insert(newSet.end(), tail.begin(), tail.end());
                // Добавляем новое множество в результирующий вектор
                result.push_back(newSet);
            }
        }

        return result;
    }

    // Функция для вывода множества в консоль
    void printSet(const std::vector<int>& set) {
        std::cout << "{ ";
        for (const auto& element : set) {
            std::cout << element << " ";
        }
        std::cout << "}\n";
    }

    // Метод для создания и инициализации произвольного числа множеств
    std::vector<std::vector<int>> CreateSets(int num) {

        std::vector<std::vector<int>> Set;

        std::cout << "Заполните множества\n";

        for (int i = 0; i < num; i++)
        {
            std::cout << "Введите размер множества " << i + 1 << ": ";
            int size;
            std::cin >> size;
            std::vector<int> set;
            std::cout << "Задайте элементы этого множества:\n";
            for (int j = 0; j < size; j++) {
                int k;
                std::cin >> k;
                set.push_back(k);
            }
            Set.push_back(set);
            std::cout << std::endl;
        }
        return Set;
    }

}