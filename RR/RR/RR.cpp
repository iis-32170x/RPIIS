#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream> 
using namespace std;

const int maxKV = 100;
int g[maxKV][maxKV];
int maxR = 1000000000;

void minR(int n) {
    vector<int> v[maxKV];            //Массив векторов, где каждый вектор представляет собой текущее множество вершин графа.
    for (int i = 0; i < n; ++i) 
        v[i].assign(1, i);           //строка кода инициализирует вектор v[i] одним элементом, равным i.
    int vesaV[maxKV];                //Массив, хранящий веса вершин.
    bool exist[maxKV], inA[maxKV];   //Массивы флагов, используемые для отслеживания существования вершин и принадлежности к множеству A.
    for (auto& element : exist)           //Устанавливает каждый элемент массива exist в значение true, чтобы все вершины были изначально отмечены как существующие.
        element = true;
    for (int ph = 0; ph < n - 1; ++ph) {  //ph - это текущая фаза алгоритма.
        for (auto& element : inA) 
            element = false;
        for (auto& element : vesaV) 
            element = 0;
        for (int it = 0, predV; it < n - ph; ++it) {//prev в данном коде является переменной, которая обозначает предыдущую вершину в контексте алгоритма нахождения минимального разреза.
            int BV = -1;                           //Хранит индекс выбранной вершины с наибольшим весом.
            for (int i = 0; i < n; ++i)             //it - переменная для подсчета итераций.
                if (exist[i] && !inA[i] && (BV == -1 || vesaV[i] > vesaV[BV])) //Находим вершину с найбольшим весом
                    BV = i;
            if (it == n - ph - 1) {
                if (vesaV[BV] < maxR)
                    maxR = vesaV[BV];
                v[predV].insert(v[predV].end(), v[BV].begin(), v[BV].end());   //Этот участок кода выполняет объединение двух множеств вершин в графе.
                for (int i = 0; i < n; ++i)
                    g[predV][i] = g[i][predV] += g[BV][i];
                exist[BV] = false;
            }
            else {
                inA[BV] = true;
                for (int i = 0; i < n; ++i) 
                    vesaV[i] += g[BV][i];
                predV = BV;
            }
        }
    }
}
void ReadMatrixFromFile(const string& fileName, int& n, int& m) {
    ifstream matrixFile(fileName);
    if (!matrixFile.is_open()) {
        cout << "Не удалось открыть файл: " << fileName << endl;
        return;
    }

    matrixFile >> n;
    matrixFile >> m;

    for (int i = 0; i < m; i++) {
        int a, b, weight;
        matrixFile >> a >> b >> weight;
        a--;
        b--;

        if (g[a][b] != 0) {
            // Если ребро уже существует, добавляем вес к существующему весу ребра
            g[a][b] += weight;
            g[b][a] += weight;
        }
        else {
            // Если это новое ребро, устанавливаем его вес
            g[a][b] = weight;
            g[b][a] = weight;
        }
    }

    matrixFile.close();
}
int main() {
    setlocale(0, "");
    int choose;
    int amountOfStrings;
    cout << "Для ввода матрицы с клавиатуры нажмите 1, для считывания с файла - не 1" << endl;
    cin >> choose;
    int n = 0;
    int m = 0;
    if (choose == 1) {

        cout << "Введите количество вершин:" << endl;
        while (!(cin >> n))//проверка на ввод нечислового значения
        {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Неправильный тип данных, введите снова" << endl;
        }
        cout << "Введите количество рёбер:" << endl;
        while (!(cin >> m))//проверка на ввод нечислового значения
        {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Неправильный тип данных, введите снова" << endl;
        }
        cout << "Введите через пробел три цифры: номера двух смежных вершин и вес ребра: " << endl;
        for (int i = 0; i < m; i++) {
            int a, b, weight;
            cin >> a >> b >> weight;
            a--;
            b--;
            if (g[a][b] != 0) {
                // Если ребро уже существует, добавляем вес к существующему весу ребра
                g[a][b] += weight;
                g[b][a] += weight;
            }
            else {
                // Если это новое ребро, устанавливаем его вес
                g[a][b] = weight;
                g[b][a] = weight;
            }

        }
    }

    else {
        ReadMatrixFromFile("matrix.txt", n, m);

    }
        
    



    
    cout << "Матрица смежности:" << endl<< endl;
    cout << setw(4) << " ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << i + 1;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << i + 1;
        for (int j = 0; j < n; j++) {
            cout << setw(4) << g[i][j];
        }
        cout << endl << endl;
    }
    minR(n);
    cout <<"Минимальный разрез"<< endl;
    cout << maxR;
    return 0;
}