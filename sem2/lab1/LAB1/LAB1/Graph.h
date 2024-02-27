#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

	class GRAPH {
		vector<vector<int>> adjacent_m;
        int vertices=0;
        int vertices_c=0;
        vector<int> visited;
        vector<int> not_visited;
	public:
		GRAPH(string path) {
            ifstream in(path);
            if (in.is_open())
            {
                int count = 0;
                int temp;
                while (!in.eof())
                {
                    in >> temp;
                    count++;
                }
                in.seekg(0, ios::beg);
                in.clear();
                int count_space = 0;
                char symbol;
                while (!in.eof())
                {
                    in.get(symbol);
                    if (symbol == ' ') count_space++;
                    if (symbol == '\n') break;
                }
                in.seekg(0, ios::beg);
                in.clear();
                vertices = count / (count_space + 1);
                vertices_c = count_space + 1;
                vector<vector<int>> copiable(vertices, vector<int>(vertices_c));
                for (int i = 0; i < vertices; i++)
                    for (int j = 0; j < vertices_c; j++)
                        in >> copiable[i][j];
                in.close();
                adjacent_m = copiable;
            }
            else
            {
                cout << "File is missing.";
            }
		}
        void PRINT_M() {
            for (int i = 0;i < adjacent_m.size();i++) {
                for (int j = 0;j < adjacent_m.size();j++) {
                    cout << "   " << adjacent_m[i][j];
                }
                cout << endl << endl;
            }
        }
        vector<vector<int>> ADD_EDGE(int node1, int node2) {
            adjacent_m[node1-1][node2-1] = 1;
            adjacent_m[node2-1][node1-1] = 1;
            return adjacent_m;

        }
        vector<vector<int>> RM_EDGE(int node1, int node2) {
            adjacent_m[node1 - 1][node2 - 1] = 0;
            adjacent_m[node2 - 1][node1 - 1] = 0;
            return adjacent_m;
        }
        vector<vector<int>> ADD_VERTICE() {
            vector<vector<int>> matrix;
            matrix = adjacent_m;
            matrix.resize(adjacent_m.size() + 1);
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i].resize(adjacent_m.size() + 1,0);
            }
            adjacent_m = matrix;
            return adjacent_m;
        }
        vector<vector<int>> RM_VERTICE(int node_to_rm) {
            vector<vector<int>> matrix;
            matrix = adjacent_m;
            if (!matrix.empty()) {
                if (node_to_rm - 1 >= 0 && node_to_rm - 1 < matrix.size()) {
                    matrix.erase(matrix.begin() + node_to_rm - 1);
                    for (int i = 0; i < matrix.size(); i++) {
                        if (!matrix[i].empty() && node_to_rm - 1 >= 0 && node_to_rm - 1 < matrix[i].size()) {
                            matrix[i].erase(matrix[i].begin() + node_to_rm - 1);
                        }
                    }
                }
            }

            adjacent_m = matrix;
            return adjacent_m;
        }
        vector<int> DFS_TREE(int node_to_start) {
            int current = node_to_start;
            not_visited.insert(not_visited.begin(), current);
            while (!not_visited.empty()) {
                visited.push_back(current);
                not_visited.erase(not_visited.begin());
                for (int i = adjacent_m.size()-1; i >= 0;i--) {
                    if (adjacent_m[current][i] != 0 && i != current && find(not_visited.begin(), not_visited.end(), i) == not_visited.end() && find(visited.begin(), visited.end(), i) == visited.end()) {
                        not_visited.insert(not_visited.begin(), i);
                        
                    }
                }
                if (!not_visited.empty()) {
                    current = not_visited.front();
                }
            }
            return visited;
        }
        void PRINT_DFS() {
            for (int i = 0;i < adjacent_m.size();i++) {
                cout << "  " << visited[i] + 1;
            }
        }
	};