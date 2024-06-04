//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int search(vector <pair<int, int>> arr, pair<int, int> key)
//{
//	for (int i = 0; i < arr.size(); i++)
//		if (arr[i] == key)
//			return i;
//	return -1;
//}
//
////void dfs(vector <vector <int>> graph, int v, int v_start, vector <bool> visited)
////{
////	if (visited[v]) {
////		if (v == v_start)
////			cout << "цикл" << endl;
////		return;
////	}
////	visited[v] = 1;
////	for (int i = 0; i < graph.size(); i++)
////		if (graph[v][i] != 0)
////			dfs(graph, i, v_start, visited);
////	visited[v] = 0;
////}
//
//void dfs(vector <vector<int>> graph, int v, int v_prev, vector <string> color, vector <pair<int, int>> visited)
//{
//	color[v] = "grey";
//	for (int i = 0; i < graph.size(); i++)
//		if (graph[v][i] != 0 and i != v_prev)
//		{
//			if (color[i] == "white")
//				dfs(graph, i, v, color);
//			if (color[i] == "grey") 
//			{
//				cout << "цикл" << endl;
//			}
//		}
//	color[v] = "black";
//}
// 
//int main()
//{
//	setlocale(0, "");
//	ifstream fin;
//	fin.open("matrix.txt");
//	int n;
//	fin >> n;
//	vector <vector <int>> gr(n, vector <int> (n));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			fin >> gr[i][j];
//	fin.close();
//	cout << "Матрица смежности: " << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			cout << gr[i][j] << " ";
//		cout << endl;
//	}
//	cout << "Введите длину цикла, который необходимо найти" << endl;
//	int len;
//	cin >> len;
//	vector <bool> visited(n, false);
//	for (int i = 0; i < n; i++)
//		dfs(gr, i, i, visited);
//}
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void find_cycles(vector<vector<int>> graph, int start, int curr, vector<bool>& visited, vector<int>& path, vector<vector<int>>& cycles) {
    visited[curr] = true;
    path.push_back(curr);
    for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
        if (graph[curr][neighbor]) {
            if (visited[neighbor]) {
                int index = path.size() - 1;
                while (path[index] != neighbor) {
                    index--;
                }
                if (index != path.size() - 2) {
                    vector<int> cycle;
                    for (int i = index; i < path.size(); ++i) {
                        cycle.push_back(path[i]);
                    }
                    cycles.push_back(cycle);
                }
            }
            else {
                find_cycles(graph, start, neighbor, visited, path, cycles);
            }
        }
    }
    visited[curr] = false;
    path.pop_back();
}

vector<vector<int>> find_all_cycles(vector<vector<int>> graph) {
    vector<bool> visited(graph.size(), false);
    vector<vector<int>> cycles;  
    for (int start = 0; start < graph.size(); start++) {
        vector<int> path;  
        find_cycles(graph, start, start, visited, path, cycles);
    }
    return cycles;
}

//void delete_repeat_cycles(vector <vector <int>>& cycles)
//{
//    for (vector <int> cycle1 : cycles)
//        for (vector <int> cycle2 : cycles)
//}

void find_all_cycles_len(vector <vector <int>> graph, int lenght)
{
    vector<vector<int>> cycles = find_all_cycles(graph);
    for (vector <int> cycle : cycles) {
        int sum = 0;
        for (int i = 0; i < cycle.size() - 1; i++) 
            sum = sum + graph[cycle[i]][cycle[i + 1]];
        sum = sum + graph[cycle[cycle.size() - 1]][cycle[0]];
        if (sum == lenght) {
            for (int v : cycle)
                cout << v + 1 << "->";
            cout << cycle[0] + 1;
            cout << endl;
        }      
    }
}

int main() {
    setlocale(0, "");
    ifstream fin;
   	fin.open("matrix.txt");
   	int n;
   	fin >> n;
   	vector <vector <int>> gr(n, vector <int> (n));
   	for (int i = 0; i < n; i++)
   		for (int j = 0; j < n; j++)
   			fin >> gr[i][j];
    fin.close();
   	cout << "Матрица смежности: " << endl;
    for (int i = 0; i < n; i++) {
   		for (int j = 0; j < n; j++)
            cout << gr[i][j] << " ";
    	cout << endl;
    }
    int len = 0;
    while (len != -1) {
        cout << "Введите длину цикла(-1 для выхода): ";
        cin >> len;
        cout << "Циклы длины " << len << ":" << endl;
        find_all_cycles_len(gr, len);
    }
}