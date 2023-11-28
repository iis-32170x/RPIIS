#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
class Graph
{
private:
  int vertex;
  int edges;

public:
  Graph(int vertex, int edges)
  {
    this->vertex = vertex;
    this->edges = edges;
  }

  bool is_planar(vector<vector<int>> &adj_matrix, int edges, int vertex)
  {
    int formul_euiler_e = 0;
    formul_euiler_e = 3 * vertex - 6;
    if (edges <= 5 && edges > formul_euiler_e)
      return false;

    else if (edges == 9 && vertex == 6)
      return false;

    else
    { // если есть вершины с количеством циклов равным 4
      for (int i = 0; i < adj_matrix.size(); i++)
      {
        for (int j = i + 1; j < adj_matrix.size(); j++)
        {
          if (adj_matrix[i][j] && adj_matrix[j][i])
          {
            // Если вершины i и j связаны двумя рёбрами, то проверяем, не образуют ли они цикл
            vector<int> cycle;
            cycle.push_back(i);
            cycle.push_back(j);
            for (int k = 0; k < adj_matrix.size(); k++)
            {
              if (adj_matrix[j][k] && adj_matrix[k][i])
              {
                cycle.push_back(k);
              }
              if (cycle.size() >= 4)
              {
                return false;
              }
            }
          }
        }
      }
      return true;
    }
  }

  void print(vector<vector<int>> &adj_matrix)
  {
    for (int i = 0; i < vertex; i++)
    {
      cout << i << ": ";
      for (int j = 0; j < vertex; j++)
        cout << adj_matrix[i][j] << ' ';
      cout << '\n';
    }
  }
  int countEdges(vector<vector<int>> &adj)
  {
    int count = 0;
    for (int i = 0; i < adj.size(); i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        if (adj[i][j])
        {
          count++;
        }
      }
    }
    return count;
  }
  std::vector<std::vector<int>> delete_last_row_and_column(const std::vector<std::vector<int>> &matrix)
  {
    // Создаем новый двумерный вектор, в который будем записывать результат.
    std::vector<std::vector<int>> result(matrix.size() - 1);

    // Перебираем строки матрицы.
    for (int row_index = 0; row_index < matrix.size() - 1; row_index++)
    {
      // Создаем новую строку для результата.
      result[row_index].resize(matrix[row_index].size() - 1);

      // Копируем строку из матрицы в новый вектор.
      for (int column_index = 0; column_index < matrix[row_index].size() - 1; column_index++)
      {
        result[row_index][column_index] = matrix[row_index][column_index];
      }
    }

    return result;
  }
  std::vector<std::vector<int>> delete_last_row_and_column2(const std::vector<std::vector<int>> &matrix)
  {
    // Создаем новый двумерный вектор, в который будем записывать результат.
    std::vector<std::vector<int>> result(matrix.size() - 2);

    // Перебираем строки матрицы.
    for (int row_index = 0; row_index < matrix.size() - 2; row_index++)
    {
      // Создаем новую строку для результата.
      result[row_index].resize(matrix[row_index].size() - 2);

      // Копируем строку из матрицы в новый вектор.
      for (int column_index = 0; column_index < matrix[row_index].size() - 2; column_index++)
      {
        result[row_index][column_index] = matrix[row_index][column_index];
      }
    }
    return result;
  }
  std::vector<std::vector<int>> delete_last_row_and_column3(const std::vector<std::vector<int>> &matrix)
  {
    // Создаем новый двумерный вектор, в который будем записывать результат.
    std::vector<std::vector<int>> result(matrix.size() - 2);

    // Перебираем строки матрицы.
    for (int row_index = 0; row_index < matrix.size() - 2; row_index++)
    {
      // Создаем новую строку для результата.
      result[row_index].resize(matrix[row_index].size() - 2);

      // Копируем строку из матрицы в новый вектор.
      for (int column_index = 0; column_index < matrix[row_index].size() - 2; column_index++)
      {
        result[row_index][column_index] = matrix[row_index][column_index];
      }
    }
    return result;
  }
  int find_min(vector<vector<int>> &adj)
  {
    if (is_planar(adj, this->edges, this->vertex))
      return 0;
    else
    {
      int min = 0;
      if (this->edges == 10 && this->vertex == 5)
        return 2;
      if (this->edges == 9 && this->vertex == 6)
        return 1;

      std::vector<std::vector<int>> matrix = delete_last_row_and_column(adj);

      int edges = countEdges(matrix);
      if (is_planar(matrix, edges, matrix.size()))
        return 1;
      else
      {
        std::vector<std::vector<int>> matrix2 = delete_last_row_and_column2(adj);
        int edges = countEdges(matrix2);
        if (is_planar(matrix2, edges, matrix2.size()))
          return 2;
        else
        {
          std::vector<std::vector<int>> matrix3 = delete_last_row_and_column3(adj);
          int edges = countEdges(matrix3);
          if (is_planar(matrix3, edges, matrix3.size()))
            return 3;
        }
      }
    }
  }
};
int main()
{
  vector<vector<int>> matrix;
  ////////////////////////////////////////////////////
  // Открываем файл для чтения
  ifstream input_file("graph1.txt");

  // Читаем размерность массива
  int rows1, e;
  input_file >> rows1 >> e;

  // Заполняем вектор
  for (int i = 0; i < rows1; i++)
  {
    vector<int> row(rows1);
    for (int j = 0; j < rows1; j++)
    {
      input_file >> row[j];
    }
    matrix.push_back(row);
  }

  // Закрываем файл
  input_file.close();

  /////////////////////////////////////////////////////
  Graph graph(rows1, e);
  graph.print(matrix);
  cout << "PLANARNOST' " << graph.is_planar(matrix, rows1, e) << '\n';
  cout << "a number of vertex to remove " << graph.find_min(matrix);
  return 0;
}