#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int amountOfStrings;
int** matrix;
int** reformedMatrix;


//Заканчивает реформирование матрицы, если каркас был создан
bool AllVertexesAreConnected(int numberOfRelations)
{
	if (numberOfRelations == amountOfStrings - 1)
	{
		return true;
	}
	return false;
}

//Проверяет было ли создана связь между вершинами
bool TheRelationsWereAlreadyCreated(int row, int column)
{
	if (reformedMatrix[row][column] == 1)
	{
		return true;
	}
	return false;
}

//Проверяет тупиковая ли вершина (остались ли от неё маршруты до ещё не исследованных вершин)
bool TheVertexDoesntHaveAnyOtherEdges(int row, int column)
{
	if (column == amountOfStrings - 1)
	{
		if (TheRelationsWereAlreadyCreated(row, column) == true)
		{
			return true;
		}
		if (matrix[row][column] == 0)
		{
			return true;
		}
	}
	return false;
}

//Проверяет была ли установлена хотя бы 1-а связь с данной вершиной
bool TheVertexIsClear(int row)
{
	for (int i = 0; i < amountOfStrings; ++i)
	{
		if (reformedMatrix[row][i] == 1)
		{
			return false;
		}
	}
	return true;
}


//Убирает кратные связи и петли
void PrepareMatrix()
{
	for (int i = 0; i < amountOfStrings; i++)
	{
		if (matrix[i][i] != 0) matrix[i][i] = 0;
		for (int j = 0; j < amountOfStrings; j++)
		{
			if (matrix[i][j] != 0 && matrix[i][j] != 1) 
				matrix[i][j] = 1;
		}
	}
}

//Читает матрицу из файла
void TakeMatrix()
{
	
	int elementOfMatrix;
	ifstream matrixFile;

	matrixFile.open("tasks\\matrixFile1.txt");
	matrixFile >> amountOfStrings;
	cout << amountOfStrings << endl;
	matrix = new int* [amountOfStrings];

	for (int k = 0; k < amountOfStrings; k++)
	{
		matrix[k] = new int[amountOfStrings];
	}

	for (int i = 0; i < amountOfStrings; i++)
	{
		for (int l = 0; l < amountOfStrings; l++)
		{
			matrixFile >> elementOfMatrix;
			matrix[i][l] = elementOfMatrix;
		}
	}


	for (int i = 0; i < amountOfStrings; i++)
	{
		for (int l = 0; l < amountOfStrings; l++)
		{
			cout << matrix[i][l] << " ";
		}
		cout << endl;
	}

	matrixFile.close();
	

	PrepareMatrix();


}

//Реформирует матрицу
void ReformMatrix()
{
	vector<int> VertexPath;
	int numberOfEdges = 0;
	int resetLevel = 1;

	reformedMatrix = new int* [amountOfStrings];
	for (int i = 0; i < amountOfStrings; i++)
	{
		reformedMatrix[i] = new int[amountOfStrings];
	}

	for (int i = 0; i < amountOfStrings; i++)
	{
		for (int j = 0; j < amountOfStrings; j++)
		{
			reformedMatrix[i][j] = 0;
		}
	}


	for (int row = 0; row < amountOfStrings; row++)
	{
		for (int column = 0; column < amountOfStrings; column++)
		{
			if (AllVertexesAreConnected(numberOfEdges) == true)
			{
				return;
			}


			if (TheVertexDoesntHaveAnyOtherEdges(row, column) == true)
			{
				row = VertexPath[numberOfEdges - resetLevel] - 1;
				++resetLevel;
				break;
			}


			if (matrix[row][column] == 1)
			{
				if (TheRelationsWereAlreadyCreated(row, column) == false)
				{
					if (TheVertexIsClear(column) == true)
					{
						reformedMatrix[row][column] = 1;
						reformedMatrix[column][row] = 1;
						resetLevel = 1;
						VertexPath.push_back(row);
						++numberOfEdges;
						row = column - 1;
						break;

					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
}

//Выводит матрицу
void ShowMatrix()
{

	cout << "\n\n\n";
	for (int i = 0; i < amountOfStrings; i++)
	{
		for (int j = 0; j < amountOfStrings; j++)
		{
			cout << reformedMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

//Очищает память
void CleanMemory()
{
	for (int k = 0; k < amountOfStrings; k++)
	{
		delete[] reformedMatrix[k];
	}
	delete[] reformedMatrix;

	for (int k = 0; k < amountOfStrings; k++)
	{
		delete[] matrix[k];
	}
	delete[] matrix;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	TakeMatrix();

	ReformMatrix();

	ShowMatrix();

	CleanMemory();
	

	return 0;
}