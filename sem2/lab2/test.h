// Подключаем заголовочный файл для ввода-вывода
#include <iostream>
// Подключаем заголовочный файл для работы с алгоритмами (next_permutation)
#include <algorithm>

// Используем стандартное пространство имен, чтобы не писать std:: перед каждой командой
using namespace std;

// Определяем класс CombinationGenerator
class CombinationGenerator {
public:
    // Количество элементов множества
    int numElements;
    // Указатель на массив элементов множества
    int* elements;

    // Конструктор класса, который принимает количество элементов множества
    CombinationGenerator(int elementsCount) : numElements(elementsCount) {
        // Выделяем память под массив элементов множества
        elements = new int[numElements];
    }

    // Метод для ввода элементов множества
    void readElements() {
        // Просим пользователя ввести элементы множества
        cout << "Введите элементы множества: ";
        // Считываем элементы множества и сохраняем их в массив
        for (int i = 0; i < numElements; i++) {
            cin >> elements[i];
        }
    }

    // Метод для генерации всех возможных комбинаций элементов множества
    void generateCombinations() {
        int combinationsCount = 0; // Счетчик комбинаций
        // Генерируем и выводим все возможные комбинации элементов множества
        do {
            // Выводим текущую комбинацию элементов
            for (int i = 0; i < numElements; i++) {
                cout << elements[i] << " ";
            }
            cout << endl; // Переходим на новую строку
            combinationsCount++; // Увеличиваем счетчик при генерации новой комбинации
        } while (next_permutation(elements, elements + numElements)); // Получаем следующую перестановку элементов
        // Выводим общее количество сгенерированных комбинаций
        cout << "Количество сгенерированных комбинаций: " << combinationsCount << endl;
    }

    // Деструктор класса, который освобождает память, выделенную под массив элементов
    ~CombinationGenerator() {
        delete[] elements;
    }
};
