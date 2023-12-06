
#include <iostream>
#include <stack>

using namespace std;

void dfs(int** mas, int n, stack<int> &fool, bool* visited)
{
	int top = fool.top();
	visited[top] = true;
	fool.pop();
	
	for (int j = 0;j < n;j++)
	{
		if (mas[top][j] == 1 && !visited[j])
		{
			fool.push(j);
		}
	}
	

	if (!fool.empty())
	{
		dfs(mas, n, fool, visited);
	}
}

bool cond(bool* visited, int n, int &start)					
{
	for (int i = 0;i < n;i++)
	{
		if (!visited[i])
		{
			start = i;
			return false;
		}
	}
	return true;
}	

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "";
	cin >> n;
	int** mas = new int* [n];
	for (int i = 0;i < n;i++)
	{
		mas[i] = new int[n];
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> mas[i][j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (mas[i][j] == 1)
			{
				mas[j][i] = 1;
			}
			
		}

	}

	stack<int> fool;
	int start = 0;

	bool* visited = new bool[n];
	for (int i = 0;i < n;i++)
	{
		visited[i] = false;
	}

	int comp = 0;

	while (!cond(visited, n, start))
	{
		fool.push(start);
		comp++;
		dfs(mas, n, fool, visited);

	}
	int sres = comp;
	cout <<"\nРезультат: ";
	
	for (int k = 0;k < n;k++)
	{
		start = 0;
		int** nmas = new int* [n - 1];
		for (int i = 0;i < n - 1;i++)
		{
			nmas[i] = new int[n - 1];
		}
		for (int i = 0;i < n;i++)
		{
			if (i != k)
			{
				for (int j = 0;j < n;j++)
				{
					if (j != k)
					{
						nmas[i - (i > k)][j - (j > k)] = mas[i][j];
						
					}

					
				}

			}
		}
		//cout << endl;
		//for (int i = 0;i < n - 1;i++)
		//{
		//	for (int j = 0;j < n - 1;j++)
		//	{
		//		cout << nmas[i][j]<<" ";
		//	}
		//	cout << endl;
		//}

		for (int i = 0;i < n-1;i++)
		{
			visited[i] = false;
		}

		comp = 0;
	
		while (!cond(visited, n-1, start))
		{
			fool.push(start);
			comp++;
			dfs(nmas, n-1, fool, visited);

		}
		if (sres < comp)
		{

			cout << k + 1 << " ";
		}

		

		for (int i = 0;i < n-1;i++)
		{
			delete[]nmas[i];
		}
		delete[]nmas;
	}

	delete[]visited;
	

	for (int i = 0;i < n;i++)
	{
		delete[]mas[i];
	}
	delete[]mas;

	return 0;
}

//0 0 1 0 0 1 0 
//0 0 1 0 0 0 0
//0 0 0 0 0 0 0
//1 0 0 0 0 0 1
//0 0 0 1 0 0 0
//0 0 0 0 1 0 0
//0 0 0 0 0 0 0 

//0 1 0
//0 0 1
//0 0 0

//0 1 0 0 0
//0 0 1 0 0
//0 0 0 1 0
//0 0 0 0 1
//0 0 0 0 0


