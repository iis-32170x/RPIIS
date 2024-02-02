#include <iostream>
#include <vector>
#include <fstream>
#include <string> 
using namespace std;

void createMatrix(int vertexCount, vector<vector<int>>& matrix) {
	cout << "Select input type:" << endl << "0) Adjacency matrix from file." << endl << "1) Keyboard input using vertex connections." << endl;

	bool choice;
	cin >> choice;
	cout << endl;

	//file

	if (choice == 0) {
		cout << "Enter the absolute path to the file: ";

		string path;

		int i = 0, j = 0;
		char sim;

		cin >> path;
		cout << endl;

		ifstream myfile(path);
		if (myfile.is_open()) {
			while (myfile.get(sim)) {
				switch (sim) {
					case '1': {
						matrix[i][j] = 1;
						j++;
						break;
					}
					case '0': {
						matrix[i][j] = 0;
						j++;
						break;
					}
					case '\n': {
						j = 0;
						i++;
						break;
					}
				}
			}
			myfile.close();
		}
		else {
			cout << "Unable to open file";
			exit(0);
		}
	}

	// keybord

	if (choice == 1) {
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
	}

	// output matrix

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


// DFS

bool DFS(int v, vector<int>& visited, vector<int>& euler, vector<vector<int>>& matrix) {
	visited.push_back(v);
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[v][i] == 1 && i != visited[visited.size()-1]) {
			matrix[v][i] = 0;
			matrix[i][v] = 0;
			DFS(i, visited, euler, matrix);
		}
	}
	if (visited.empty()) {
		return 1;
	}
	euler.push_back(v);
	visited.pop_back();
	if (visited.empty()) {
		return 1;
	}
	v = visited[visited.size() - 1];
	visited.pop_back();
	DFS(v, visited, euler, matrix);
}

bool isEuler(int vertexCount, int startVetrex, vector<int>& visited, vector<int>& euler, vector<vector<int>>& matrix) {

	// check if number of vertices have odd degree 

	for (int i = 0; i < vertexCount; i++) {
		int counter = 0;
		for (int j = 0; j < vertexCount; j++) {
			if (matrix[i][j] == 1) {
				counter++;
			}
		}
		if (counter % 2 != 0 || counter == 0) {
			return 0;
		}
	}

	// start DFS

	return DFS(startVetrex, visited, euler, matrix);
} 

int main() {
	int vertexCount;
	cout << "Enter number of vertex: ";
	cin >> vertexCount;
	cout << endl;

	vector<vector <int>> matrix(vertexCount, vector<int>(vertexCount));

	createMatrix(vertexCount, matrix);

	cout << endl << "Enter the number of the vertex with which you want to start checking the cycle: ";
	int startVertex;
	cin >> startVertex;
	cout << endl;

	vector<int> visited;
	vector<int> euler;

	if (isEuler(vertexCount, startVertex, visited, euler, matrix)) {
		cout << "The graph contains an Euler cycle: ";
		for (int i = 0; i < euler.size(); i++) {
			cout << euler[i] << " ";
		}
		cout << endl;
		cout << "Eulerian cycle length: " << euler.size()-1;
	}
	else {
		cout << "The graph does not contains an Euler cycle." << endl;
	}
}
