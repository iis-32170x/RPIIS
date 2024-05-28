# Лабораторная работа №2

Вариант 9. Реализовать программу, проверяющую, является ли одно или оба из исходных множеств подмножеством или элементом другого.

## Ключевые понятия

`Множество` – простейшая информационная конструкция и математическая структура, позволяющая рассматривать какие-то объекты как целое, связывая их.

Все вхождения, которые имеет любое ориентированные множество, упорядочены. Два ориентированных множества равны тогда и только тогда, когда все их элементы входят в одинаковом порядке.

## Описание алгоритмов и структур:

Для хранения множеств, их подмножеств и элементов используется структура Array
```c++
struct Array // структура, описывающая множество
{
    string Type,Str;
    int ElementsNum;
    vector<Array*> SubsetItems; 

    Array(string type, int numberOfItems, string str); // конструктор с параметрами
};
```

А также конструктор для заполнения множества:
```c++
Array::Array(string type, int numberOfItems, string str) // конструктор
{
    if (type == "элемент")
    {
        Type = type;
        ElementsNum = numberOfItems;
        Str = str;
    }
    if (type == "множество" || type == "кортеж")
    {
        Type = type;
        ElementsNum = numberOfItems;
        SubsetItems.resize(numberOfItems);
    }
}
```

Для извлечения множества из строки в файле или консоли используется фунция ArrayCreation:
```c++
Array* ArrayCreation(string str) // Создаём множество из строки
{

    Array* result;
    string type;
    // startPos - начальная позиция текущего подмножества в строке
    // endPos - конечная позиция текущего подмножества в строке
    // count - количество элементов в создаваемом массиве
    // openArr - количество открытых скобок множеств
    // openCourt - количество открытых скобок кортежей
    int startPos = 0, endPos = 0, count = 0, openArr = 0, openCourt = 0;
    //Считываем количество элементов в массиве, заодно считая скобки
    // Обработка пустого множества: если строка состоит только из "{}"
    if (str == "{}") {
        result = new Array("множество", 0, str);
        return result;
    }
    for (int i = 1; i < str.length() - 1; i++)
    {
        if (str[i] == '{') {
            openArr++;
        }
        if (str[i] == '}') {
            openArr--;
        }
        if (str[i] == '<') {
            openCourt++;
        }
        if (str[i] == '>') {
            openCourt--;
        }
        //Если найдена запятая, а счётчики скобок равны нулю, то засчитываем новый элемент
        if (str[i] == ',' && openArr == 0 && openCourt == 0) {
            count++;
        }
    }
    //Определяем, чем является строка по первому символу
    if (str[0] == '{') {
        type = "множество";
    }
    else if (str[0] == '<') {
        type = "кортеж";
    }
    else
    {
        Array* arr = new Array("элемент", 1, str);
        return arr;
    }
    count++; //Увеличиваем счётчик ещё на 1, потому что после последнего элемента нет запятой
    result = new Array(type, count, str);
    int i = 0;
    while (i < count)
    {
        // Если startPos равен 0 или указывает на запятую, значит это начало нового элемента
        if (startPos == 0 || str[startPos] == ',')
        {
            startPos++;// Сдвигаем startPos на следующий символ
        }
        // Если endPos указывает на конец строки или запятую, значит это конец текущего элемента
        if (endPos == str.length() - 1 || str[endPos] == ',')
        {
            endPos--;//Сдвигаем endPos на предыдущий символ
            // Обнуляем счетчики открытых скобок
            openArr = 0;
            openCourt = 0;
            // Проходим по строке от начала текущего элемента до его конца
            for (int j = 1; j <= endPos; j++)
            {
                if (str[j] == '{') {
                    openArr++;
                }
                else if (str[j] == '<') {
                    openCourt++;
                }
                else if (str[j] == '}') {
                    openArr--;
                }
                else if (str[j] == '>') {
                    openCourt--;
                }
            }
            // Если счетчики открытых скобок равны нулю, значит подстрока является корректным подмножеством
            if (openArr == 0 && openCourt == 0)
            {
                // Рекурсивно создаем подмножество из подстроки и записываем в SubsetItems[i]
                result->SubsetItems[i] = ArrayCreation(str.substr(startPos, endPos - startPos + 1));
                startPos = endPos + 1;// Перествляем startPos на начало следующего элемента после запятой
                endPos = startPos;
                i++;//Переходим к следующему элементу
            }
            // Если счетчики открытых скобок не равны нулю, значит подстрока не является корректным подмножеством
            else
            {
                endPos++; // Сдвигаем endPos на следующий символ
            }
        }

        endPos++;
    }
    return result;//возвращаем полученный результат
}
```

Для проверки является ли множество подмножеством другого используется функция IsSubset
```c++
bool InSubset(Array* arr1, Array* arr2) {
    bool isInSecond = false;
    if (arr1->Type != "элемент" && arr2->Type != "элемент") {
        vector<bool> used(arr2->ElementsNum, false);
        for (int i = 0; i < arr1->ElementsNum; i++) {
            isInSecond = false;
            for (int j = 0; j < arr2->ElementsNum; j++) {
                // Проверяем, не был ли этот элемент arr2 уже использован 
                // и совпадают ли тип и количество элементов в текущих элементах arr1 и arr2
                if (!used[j] && arr1->SubsetItems[i]->ElementsNum == arr2->SubsetItems[j]->ElementsNum && arr1->SubsetItems[i]->Type == arr2->SubsetItems[j]->Type) {
                    // Если arr1 - кортеж и j > i, то порядок элементов нарушен, возвращаем false 
                    if (arr1->Type == "кортеж" && j > i) {
                        return false;
                    }
                    //Рекурсивно проверяем вложеные элементы
                    isInSecond = InSubset(arr1->SubsetItems[i], arr2->SubsetItems[j]);
                    // Если элементы совпали, отмечаем элемент arr2 как использованный и выходим из внутреннего цикла
                    if (isInSecond) {
                        used[j] = true;
                        break;
                    }
                }
                // Проверка, является ли arr1 кортежем, а arr2 множеством,
                // и совпадает ли arr1 с элементом arr2
                if (!used[j] && arr1->Type == "кортеж" && arr2->Type == "множество" && InSubset(arr1, arr2->SubsetItems[j])) {
                    return true;
                }
                // Проверка, является ли arr2 элементом, а arr1 - кортежем,
                // и совпадает ли arr2 с элементом arr1
                if (!used[j] && arr2->Type == "элемент" && arr1->Type == "кортеж" && InSubset(arr2, arr1->SubsetItems[j])) {
                    return true;
                }
            }
            if (!isInSecond) {
                return false;
            }
        }
    }

    else if (arr1->Type == "элемент" && arr2->Type == "элемент" && arr1->Str == arr2->Str)
    {
        return true;
    }
    else {
        return false;
    }
    return true;
}
```

С помощью IsCorrect проверяется корректность строки
```c++
bool IsCorrect(string str) // проверка на правильность введённой строки
{
    if (str.find("><") != -1 || str.find("}{") != -1) {
        cout << "Элементы должны разделяться запятой\n";
        return false;
    }
    int openArr = 0;
    int openCourt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            openArr++;
        if (str[i] == '<')
            openCourt++;
        if (str[i] == '}')
            openArr--;
        if (str[i] == '>')
            openCourt--;
    }
    if (openArr != 0 || openCourt != 0) {
        cout << "В строке допущена ошибка\n";
        return false;
    }
    return true;
}
```

Функция Remove очищает память
```c++
void Remove(Array* arr) // Очистка множества
{
    if (arr->Type == "элемент")
    {
        delete arr;
        return;
    }
    for (int i = 0; i < arr->ElementsNum; i++)
    {
        Remove(arr->SubsetItems[i]);
    }
    delete arr;
    return;
}
```

Функция GetResult выводит полученный результат на экран
```c++
void GetResult(Array* arr1, Array* arr2) // Получение результата
{

    if (InSubset(arr1, arr2) && InSubset(arr2, arr1))
        cout << "Равны" << endl;
    else
    {
        cout << "Не равны" << endl;
        if (InSubset(arr1, arr2))
            cout << "A - подмножнство B" << endl;
        else if (InSubset(arr2, arr1))
            cout << "B - подмножество A" << endl;
        else if (arr1->Type != "элемент" && arr2->Type != "элемент")
        {
            for (int i = 0; i < arr1->ElementsNum; i++)
            {
                if (InSubset(arr1->SubsetItems[i], arr2) && InSubset(arr2, arr1->SubsetItems[i]))
                {
                    cout << "B - элемент A" << endl;
                    break;
                }
            }
            for (int i = 0; i < arr2->ElementsNum; i++)
            {
                if (InSubset(arr2->SubsetItems[i], arr1) && InSubset(arr1, arr2->SubsetItems[i]))
                {
                    cout << "A - элемент B" << endl;
                    break;
                }
            }
        }
        else if (arr1->Type == "элемент" && arr2->Type == "множество") {
            for (int i = 0; i < arr2->ElementsNum; i++) {
                if (InSubset(arr1, arr2->SubsetItems[i]) && InSubset(arr2->SubsetItems[i], arr1)) {
                    cout << "А - элемент В\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "элемент" && arr1->Type == "множество") {
            for (int i = 0; i < arr1->ElementsNum; i++) {
                if (InSubset(arr2, arr1->SubsetItems[i]) && InSubset(arr1->SubsetItems[i], arr2)) {
                    cout << "В - элемент А\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "элемент" && arr1->Type == "кортеж") {
            for (int i = 0; i < arr1->ElementsNum; i++) {
                if (InSubset(arr2, arr1->SubsetItems[i]) && InSubset(arr1->SubsetItems[i], arr2)) {
                    cout << "В - элемент А\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "кортеж" && arr1->Type == "элемент") {
            for (int i = 0; i < arr2->ElementsNum; i++) {
                if (InSubset(arr1, arr2->SubsetItems[i]) && InSubset(arr2->SubsetItems[i], arr1)) {
                    cout << "А - элемент В\n";
                    break;
                }
            }
        }
    }
}
```

## Тестирование

![1](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/sem2/img/изображение_2024-05-26_190439889.png)

Вводим обе строки, программа выдаёт результат, что В - подмножество А

![2](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/sem2/img/изображение_2024-05-26_190945214.png)

Проверка на правильность обработки пустых множеств. Программа выдаёт корректный результат

## Источники

https://drive.google.com/file/d/1j-PsJSuN9RiMik3-pWwBjYyqLicLuCfG/view - задание и теория

https://aistudio.google.com/app/?hl=ru - помощь с дебагом кода 

https://github.com/iis-32170x/RPIIS/blob/Самович_В/sem2/lab2/lr2.md - идея реализации

