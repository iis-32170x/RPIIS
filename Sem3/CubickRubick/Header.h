/// @file
/// @brief Определения классов Face и Cube для работы с кубиком.

#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

/**
    \brief Классс Face представляет одну сторону кубика.

    *Класс содержит в себе матрицу грани кубика, функции для корректного вывода грани и оператры для работы с гранями.
*/
class Face
{
public:
    /// @brief Матрица, представляющая сторону кубика.
    vector<vector<char>> Matrix;
    /**
    \brief Карта для функции рандомизации кубика.

    *Карта хранит в себе уже созданные функцией случайные ячейки для предотвращения создания во второй раз.
*/
    map<vector<int>,bool> RandomCounter;
    /// @brief Конструктор с параметром.
    /// @param Color Цвет грани
    Face(char);
    /// @brief Вывод заголовка.
    /// @param DisplayedFaces Вектор сторон кубика.
    void OutPutHeader(vector<Face>);
    /// @brief Вывод заголовка.
    /// @param DisplayedFaces Вектор сторон кубика.
    void OutPutBody(vector<Face>);
    /// @brief Вывод заголовка.
    /// @param DisplayedFaces Вектор сторон кубика.
    void OutPutFooter(vector<Face>);
    /**
    \brief Форматированный вывод ячейки грани.

    *Функция преобразует буквенные значения ячеек грани в понятные для пользователя цветные ячейки.
*/
    /// @param MatrixMember Ячейка грани.
    /// @return Символ цветного квадрата.
    string SquareOutPut(char);

    /// @brief Оператор присваивания.
    /// @param other Другая сторона кубика.
    /// @return Текущая сторона.
    Face& operator=(const Face& other);
    /// @brief Оператор неравенства.
    /// @param other Другая сторона кубика.
    /// @return true, если стороны не равны.
    bool operator!=(const Face& other) const;
    /// @brief Оператор равенства.
    /// @param other Другая сторона кубика.
    /// @return true, если стороны равны.
    bool operator==(const Face& other) const;

private:
    /// @brief Красный квадрат для визуализации.
    const string RedSquare = "\033[31m#\033[0m";
    /// @brief Синий квадрат для визуализации.
    const string BlueSquare = "\033[34m#\033[0m";
    /// @brief Оранжевый квадрат для визуализации.
    const string OrangeSquare = "\033[38;5;208m#\033[0m";
    /// @brief Жёлтый квадрат для визуализации.
    const string YellowSquare = "\033[33m#\033[0m";
    /// @brief Зелёный квадрат для визуализации.
    const string GreenSquare = "\033[32m#\033[0m";
    /// @brief Белый квадрат для визуализации.
    const string WhiteSquare = "\033[37m#\033[0m";
};

/**
    \brief  Класс Cube представляет весь кубик.

    *Класс содержит методы для управления и манипуляций кубиком Рубика.
*/
class Cube
{
public:
    Face Front /** @brief Передняя грань кубика. */, Top /** @brief Верхняя грань кубика. */, Back/** @brief Задняя грань кубика. */, 
        Bottom /** @brief Нижняя грань кубика. */, Left /**  @briefЛевая грань кубика. */, Right /**  @brief Правая грань кубика. */, 
        BufferFace /** @brief Буферная грань кубика.
                   
                   Нужна для работы функций фращения граней кубика
                   */;
    /**
    \brief Конструктор класса.

    *При создании объекта данного класса создаётся вектор, хранящий грани в правильном порядке, переменные для управления классами и список цветов граней.
*/
    Cube();
    /// @brief Вектор для хранения цветов граней.
    vector<char> ColorsList;
    /**
    \brief Карта для функции рандомизации кубика.

    *Карта хранит в себе информацию о том, сколько раз использовался определённый цвет при функции рандомизации кубика.
*/
    map<char, int> ColorsCounter;
    /// @brief Переменная, хранящая количество уже сгенерированных случайных ячеек кубика.
    int FullRandomCounter;
    /// @brief Функция передачи вектора граней для тестирования програмы.
    vector<Face> GetDisplayedFace() const;
    /// @brief Функия для вывода кубика на экран.
    void FaceOutPut(Face, vector<Face>);
    /// @brief Функция вращения ячеек грани на 90 градусов.
    /// @param SelectionFace Сторона для вращения.
    /// @param clockwise Направление вращения.
    Face FaceCoup(Face, bool);
    /// @brief Функция изменения состояния граней в векторе.
    /// @param PrintedFace Вектор изменённых граней.
    void FaceSynchron(vector<Face>);
    /// @brief Рандомизации кубика.
    /// @param DisplayedFaces Вектор граней кубика.
    void Randomize(vector<Face>);
    /// @brief Функция чтения граней кубика из файла.
    /// @param PrintedFace Вектор граней.
    void CubeReading(vector<Face>);
    /**
    \brief Функия вертикального вращения столбца грани.

    *Функция вращает столбец ячеек грани кубика в направлении, 
    выбранным пользователем, вместе с вращение на 90 градусов боковой грани, связанной со столбцом ячеек.
*/
    /// @param DisplayedFaces Вектор граней.
    /// @param SeriesNumber Номер столбца для вращения.
    /// @param Up Направление вращения.
    void VerticalFaceTurn(vector<Face>, int, bool);
    /**
   \brief Функия горизонтального вращения столбца грани.

   *Функция вращает строку ячеек грани кубика в направлении,
   выбранным пользователем, вместе с вращение на 90 градусов верхней или нижней грани, связанной со столбцом ячеек.
*/
/// @param DisplayedFaces Вектор граней.
/// @param SeriesNumber Номер строки для вращения.
/// @param LeftRotatin Направление вращения.
    void HorisontalFaceTurn(vector<Face>, int, bool);
    /**
   \brief Функия полного вращения грани на 90 градусов.

   *Функция вращает переднюю грань на 90 градусов вместе с вращением близлежащих ячеек других граней.
*/
/// @param DisplayedFaces Вектор граней.
/// @param clockwise Направление вращения.
    void FaceTurn(vector <Face>, bool);
    /**
   \brief Функия выбора и вращения грани.

   *Функция считывает нажатую клавишу и вращает связанную с этой клавишой грань/столбец/строка.
*/
/// @param ch Нажатая кнопка.
    void FaceTorsion(char);
    /**
   \brief Функция вращения кубика в пространстве.

   *Функция считывает нажатую клавишу и вращает кубик в пространстве или даёт команду на рандомизацию, чтение
   из файла и проверку собранности. Иначе передаёт нажатую клавижу в функцию вращения граней.
*/
/// @param ch Нажатая кнопка.
    void FaceChoosing(char);
    /// @brief Проверка собранности кубика.
    /// @param DisplayedFaces Вектор граней кубика.
    int Examination(vector<Face>);
    /// @brief Функция вызова отображения и ожидания действий пользователя.
    void Game();

private:
    /// @brief Вектор, хранящий в правильном порядке грани кубика.
    vector<Face> DisplayedFace;
    int CellsNumbers /** @brief Переменняе, хранящая количество ячеек в кубике. */, 
        ColorsNumbers/** @brief Переменная, хранящая количество цветов. */,
        SideCellsNumbers/** @brief Переменная, хранящая количество ячеек в грани. */,
        LineCellsNumbers/** @brief Переменная, хранящая количество ячеек в строк/столбце. */,
        SideNumbers/** @brief Переменная, хранящая количество сторон. */;
};