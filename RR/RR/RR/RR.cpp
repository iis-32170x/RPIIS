#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int amountOfStrings;
int** matrix;
int** reformedMatrix;


bool AllVertexesAreConnected(int numberOfRelations)
{
	if (numberOfRelations == amountOfStrings - 1)
	{
		return true;
	}
	return false;
}

bool TheRealtionsWereAlreadyCreated(int row, int column)
{
	if (reformedMatrix[row][column] == 1)
	{
		return true;
	}
	return false;
}

bool TheVertexDoesntHaveAnyOtherEdge(int row, int column)
{
	if (column == amountOfStrings - 1)
	{
		if (TheRealtionsWereAlreadyCreated(row, column) == true)
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



void PrepareMatrix()
{
	for (int i = 0; i < amountOfStrings; i++)
	{
		if (matrix[i][i] != 0) matrix[i][i] = 0;
		for (int j = 0; j < amountOfStrings; j++)
		{
			if (matrix[i][j] != 0 && matrix[i][j] != 1) matrix[i][j] = 1;
		}
	}
}

void TakeMatrix()
{
	
	int elementOfMatrix;
	ifstream matrixFile;

	matrixFile.open("matrixFile.txt");
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


void ReformMatrix()
{
	vector<int> VertexPath;
	int numberOfEdges = 0;
	int resetLevel = 1;

	reformedMatrix = new int* [amountOfStrings];
	for (int k = 0; k < amountOfStrings; k++)
	{
		reformedMatrix[k] = new int[amountOfStrings];
	}

	

	for (int i = 0; i < amountOfStrings; i++)
	{
		for (int l = 0; l < amountOfStrings; l++)
		{
			reformedMatrix[i][l] = 0;
		}
	}


	for (int k = 0; k < amountOfStrings; k++)
	{
		for (int l = 0; l < amountOfStrings; l++)
		{
			if (AllVertexesAreConnected(numberOfEdges) == true)
			{
				return;
			}


			if (TheVertexDoesntHaveAnyOtherEdge(k, l) == true)
			{
				k = VertexPath[numberOfEdges - resetLevel] - 1;
				++resetLevel;
				break;
			}


			if (matrix[k][l] == 1)
			{
				if (TheRealtionsWereAlreadyCreated(k, l) == false)
				{
					if (TheVertexIsClear(l) == true)
					{
						reformedMatrix[k][l] = 1;
						reformedMatrix[l][k] = 1;
						resetLevel = 1;
						VertexPath.push_back(k);
						++numberOfEdges;
						//cout << endl << numberOfEdges << endl;
						k = l - 1;
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