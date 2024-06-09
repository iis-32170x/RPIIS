# Отчет по расчетной работе по дисциплине ПиОИвИС

### Цель:
Ознакомиться с  основами теории графов, способами представления графов, базовыми алгоритмами для работы с разными видами графов.
### Условие задания
Найти минимальное множество рёбер неориентированного графа, удаление  
которых позволяет сделать его планарным
Граф задается матрицей инцидентности данные который читаются из файла.
Вывод работы программы выводиться в консоль.
### Базовые понятия 
- **Граф** - совокупность двух множеств множества самих объектов, называемого множеством вершин, и множества их парных связей, называемого множеством рёбер.
- **Неориентированный** граф-граф, в котором все ребра являются звеньями, то есть порядок двух концов ребра графа не существенен.
- Граф называется *планарным* если все его вершины можно поместить  на одной плоскости.
- **Степень вершины** графа-количество ребер, для которых она является концевой (при этом петли считают дважды).
- Граф называется *непланарным*,если граф содержит графы гомеоморфные графам K<sub>5</sub> и K<sub>3,3</sub>
- **Планарный граф** — это граф, который можно нарисовать на плоскости без пересечения ребер. Другими словами, граф является плоским, если его можно вложить в плоскость так, чтобы никакие ребра не пересекались
- **Неориентированный граф - это граф, рёбра которого не имеют направления.
- **Матрица инцидентности** - это способ представления графа в виде матрицы. В этой матрице каждая строка соответствует одной вершине графа, а каждый столбец соответствует ребру графа. Элемент матрицы на пересечении строки i и столбца j равен 1, если ребро j либо выходит либо входит в точку i, и 0, в противном случае.
### Алгоритм решения

Чтобы найти минимальное количество рёбер которые необходимо удалить, чтобы непланарный граф стал планарным нам необходимо узнать не является ли этот граф уже планарным. Если он оказался планарным сразу выводим сообщение о том что граф планарный.

В итоге проверив планарность графа c помощью алгоритма Боера Мурвольда, переходим к поиску минимального множества рёбер которые необходимо удалить. Сгенерируем все возможные наборы(из подграфа куратовского) из 1 ребра. Будем по очереди удалять эти рёбра из графа и каждый раз проверять новый граф на планарность. После того как мы попробовали удалить все рёбра, мы генерируем все возможные комбинации из 2 ребер. Будем по очереди удалять набор этих рёбер из графа и каждый раз проверять новый граф на планарность. Так продолжаем до тех пор пока не обнаружим то самое минимальное множество рёбер.


Вот пример кода:
~~~c++
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/ref.hpp>
#include <vector>

#include <boost/graph/boyer_myrvold_planar_test.hpp>
#include <boost/graph/is_kuratowski_subgraph.hpp>

std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<int>> matrix;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}



using namespace boost;

void generateEdgeCombinations(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<std::vector<int>>>& combinations, std::vector<std::vector<int>>& currentCombination, int n, int column = 0) {
    if (currentCombination.size() == n) {
        combinations.push_back(currentCombination);
        return;
    }

    if (column == matrix[0].size()) {
        return;
    }

    // Выбираем текущий столбец матрицы
    std::vector<int> selectedColumn;
    for (std::size_t row = 0; row < matrix.size(); ++row) {
        selectedColumn.push_back(matrix[row][column]);
    }

    currentCombination.push_back(selectedColumn);
    generateEdgeCombinations(matrix, combinations, currentCombination, n, column + 1);
    currentCombination.pop_back();

    // Пропускаем текущий столбец матрицы
    generateEdgeCombinations(matrix, combinations, currentCombination, n, column + 1);
}

int main(int argc, char** argv) {
    typedef adjacency_list
        <vecS,
        vecS,
        undirectedS,
        property<vertex_index_t, int>,
        property<edge_index_t, int>
        >
        graph;

    std::string filename = "inputgraph.txt";
    std::vector<std::vector<int>> InputMatrix = readMatrixFromFile(filename);

    int num_rows = InputMatrix.size();
    int num_col = InputMatrix[0].size();

    for (const auto& row : InputMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    graph g(num_rows);

    for (int ed = 0; ed < num_col; ed++) {
        for (int v_beg = 0; v_beg < num_rows - 1; v_beg++) {
            for (int v_end = v_beg + 1; v_end < num_rows; v_end++) {
                if (InputMatrix[v_beg][ed] == 1 and InputMatrix[v_end][ed] == 1) add_edge(v_beg, v_end, g);
            }
        }
    }

    // Initialize the interior edge index
    property_map<graph, edge_index_t>::type e_index = get(edge_index, g);
    graph_traits<graph>::edges_size_type edge_count = 0;
    graph_traits<graph>::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
        put(e_index, *ei, edge_count++);

    // Test for planarity. We just want to 
    // compute the kuratowski subgraph as a side-effect
    typedef std::vector<graph_traits<graph>::edge_descriptor> kuratowski_edges_t;
    kuratowski_edges_t kuratowski_edges;
    if (boyer_myrvold_planarity_test(boyer_myrvold_params::graph = g,
        boyer_myrvold_params::kuratowski_subgraph =
        std::back_inserter(kuratowski_edges)
    ))
        std::cout << "Input graph is planar" << std::endl;
    else {
        std::cout << "Input graph is not planar" << std::endl;

        std::cout << "Edges in the Kuratowski subgraph: ";
        kuratowski_edges_t::iterator ki, ki_end;
        ki_end = kuratowski_edges.end();

        int num_columns = 0;
        for (ki = kuratowski_edges.begin(); ki != ki_end; ++ki) {
            std::cout << *ki << " ";
            num_columns++;
        }
        std::cout << std::endl;

        std::vector<std::vector<int>> matrix(num_rows, std::vector<int>(num_columns, 0));

        int i = 0;
        for (ki = kuratowski_edges.begin(); ki != ki_end; ++ki) {
            // Получение дескриптора ребра
            graph_traits<graph>::edge_descriptor edge = *ki;
            matrix[source(edge, g)][i] = 1;
            matrix[target(edge, g)][i] = 1;
            i++;
        }
        for (std::size_t j = 0; j < matrix.size(); j++) {
            for (std::size_t i = 0; i < num_columns; i++) {
                std::cout << matrix[j][i] << " ";
            }
            std::cout << std::endl;
        }

        std::vector<std::vector<std::vector<int>>> combinations;
        std::vector<std::vector<int>> currentCombination;
        bool ya = false;

        for (int x = 1; x < matrix[0].size(); x++)
        {
            generateEdgeCombinations(matrix, combinations, currentCombination, x);
            // Вывод всех комбинаций ребер в виде матрицы инцидентности
            for (std::size_t i = 0; i < combinations.size(); ++i) {
                graph g_t(g);
                const std::vector<std::vector<int>>& combination = combinations[i];
                for (std::size_t j = 0; j < combination.size(); ++j) {

                    // Вывод ребра текущей комбинации
                    for (ki = kuratowski_edges.begin(); ki != ki_end; ++ki) {
                        // Получение дескриптора ребра
                        graph_traits<graph>::edge_descriptor edge = *ki;
                        if (combination[j][source(edge, g)] == 1 and combination[j][target(edge, g)])
                        {
                            remove_edge(source(edge, g_t), target(edge, g_t), g_t);
                        }
                    }

                }
                if (boyer_myrvold_planarity_test(g_t)) {
                    std::cout << "Minimal graph found" << std::endl;
                    for (int i = 0; i < combination[0].size(); i++) {
                        for (int j = 0; j < combination.size(); j++) {
                            std::cout << combination[j][i] << " ";
                        }
                        std::cout << std::endl;
                    }
                    ya = true;
                    break;
                }

            }
            if (ya)
                break;
        }

    }
    return 0;
}

~~~


### Примеры Работы программы

![image](https://github.com/iis-32170x/RPIIS/assets/144806982/dc56c765-fb82-411d-928a-48608205ea16)

![image](https://github.com/iis-32170x/RPIIS/assets/144806982/2bb44e2d-c898-4c52-b03d-fdf97454e8b5)

![image](https://github.com/iis-32170x/RPIIS/assets/144806982/aa4dd20c-a59d-4ed5-b3c9-29d459ccd66e)

![image](https://github.com/iis-32170x/RPIIS/assets/144806982/febae437-eff9-4983-8f37-82aaa1eeb5c2)




### Вывод

В результате выполнения данной работы были получены следующие практические навыки:
- изучены основы теории графов
- изучены способы представления графов
- изучены базовые алгоритмы для работы с графами
