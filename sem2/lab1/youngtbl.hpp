#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class YoungTableau
{
    private:
        // Здесь таблица Юнга исполнена в виде вектора векторов
        std::vector<std::vector<int>> table;

    public:
        // Инициализация таблицы
        void initialize(int row_number)
        {
            // Если таблица непустая, она предварительно очищается
            if (!table.empty())
            {
                for (auto& row : table)
                    row.clear();
                table.clear();
            }
            // Таблица создаётся из данного количества пустых строк
            for (int i = 0; i < row_number; i++)
            {
                table.push_back({});
            }
        }

        // Определение количества строк в таблице
        size_t width()
        {
            return table.size();
        }

        // Добавление элемента в определённую строку таблицы
        void add(int line_number, int element)
        {
            table[line_number-1].push_back(element);
        }

        // Удаление первого появления элемента в таблице
        void remove(int element)
        {
            // Переменная "содержится ли данный элемент в таблице"
            bool in_table = 0;
            
            // Проход по каждой строке таблицы
            for (auto& row : table)
            {
                auto it = std::find(row.begin(), row.end(), element);

                // Если элемент найден, удаляем его и завершаем процедуру
                if (it != row.end())
                {
                    row.erase(it);
                    std::cout << "Из таблицы был удалён первый встретившийся элемент " << element << ".\n";
                    break;
                }
            }
            // Если данного элемента в таблице нет, выводим соответствующее сообщение
            if (!in_table)
                std::cout << "Данного элемента нет в таблице.\n";
        }

        // Удаление всех появлений элемента в таблице
        void removeAll(int element)
        {
            // Переменная "содержится ли данный элемент в таблице в количестве не менее одного"
            bool in_table = 0;

            for (auto& row : table)
            {
                // Проход по строке таблицы проводится столько раз, чтобы данного элемента в строке не осталось
                while(1)
                {
                    auto it = std::find(row.begin(), row.end(), element);

                    // Если элемент найден, удаляем его
                    if (it != row.end())
                    {
                        row.erase(it);
                        in_table = 1;
                    }
                    // Иначе переходим к следующей строке
                    else break;
                }
            }
            // Если данного элемента в таблице нет, выводим соответствующее сообщение
            if (!in_table)
                std::cout << "Данного элемента нет в таблице.\n";
            else
                std::cout << "Из таблицы были удалены все элементы " << element << ".\n";
        }

        // Вывод таблицы на экран
        void print()
        {
            // Если таблица пуста, сообщаем об этом
            if (table.size() == 0)
                std::cout << "\nТаблица пуста.\n";
            // Иначе выводим её целиком
            else
            {
                std::cout << "\nТаблица Юнга:\n";
                for (auto& row : table)
                {
                    for (int element : row)
                    {
                        std::cout << element << " ";
                    }
                    std::cout << "\n";
                }
            }
        }

        // Вывод таблицы в файл
        void printToFile(std::string filename)
        {
            std::ofstream fout(filename);
			// Если таблица пуста, сообщаем об этом
            if (table.size() == 0)
                fout << "Таблица пуста.";
            // Иначе выводим её целиком
            else
            {
                fout << "Таблица Юнга:";
                for (auto& row : table)
                {
                    fout << "\n";
					for (int element : row)
                    {
                        fout << element << " ";
                    }
                }
            }

            std::cout << "Таблица была выведена в " << filename << ".\n";
        }
};
