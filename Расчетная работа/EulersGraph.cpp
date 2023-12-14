#include <iostream>
#include <vector>
using namespace std;

void createMatrix(int vertexCount, vector<vector<int>>& matrix) {
	cout << "Enter the elements of an undirected graph with a connection (element numbers start from 0)." << endl;
	cout << "* If you want to stop entering, enter -1." << endl;

	while (true) {
		int a, b;
		cin >> a;
		if (a == -1) {
			cout << endl << "Entry completed." << endl;
			break;
		}
		cin >> b;

		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	cout << "  ";

	for (int i = 0; i < vertexCount; i++) {
		cout << i << " ";
	}

	cout << endl;

	for (int i = 0; i < vertexCount; i++) {
		cout << i << " ";
		for (int j = 0; j < vertexCount; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


void DFS(int v, int counter, vector<int>& visited, vector<vector<int>>& matrix) {
	visited.push_back(v);
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[v][i] == 1 && v != visited[counter]) {
			matrix[v][i] = 0;
			matrix[i][v] = 0;
			counter++;
			cout << counter << endl;
			DFS(i, counter, visited, matrix);
		}
	}
}

bool isEuler(int vertexCount, int startVetrex, vector<int>& visited, vector<vector<int>>& matrix) {
	for (int i = 0; i < vertexCount; i++) {
		int counter = 0;
		for (int j = 0; j < vertexCount; j++) {
			if (matrix[i][j] == 1) {
				counter++;
			}
		}
		if (counter % 2 != 0 || counter == 0) {
			return(0);
		}
	}

	DFS(startVetrex, 0, visited, matrix);
}

int main() {
	int vertexCount;
	cout << "Enter number of vertex: ";
	cin >> vertexCount;
	cout << endl;

	vector<vector <int>> matrix(vertexCount, vector<int>(vertexCount));

	createMatrix(vertexCount, matrix);

	vector<int> visited;

	cout << endl << "Enter the number of the vertex with which you want to start checking the cycle: ";
	int startVertex;
	cin >> startVertex;
	cout << endl;

	if (isEuler(vertexCount, startVertex, visited, matrix)) {
		cout << "The graph contains an Euler cycle: ";
		for (int i = 0; i < visited.size(); i++) {
			cout << visited[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "The graph does not contains an Euler cycle." << endl;
	}
}