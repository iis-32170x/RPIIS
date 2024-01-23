#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int get_nodes_count(std::ifstream &file)
{
    std::string first_line;
    file >> first_line; 
    file.seekg(0);

    return first_line.length();
}


vector<vector<bool>> create_graph(std::ifstream &file, int nodes_count)
{
    vector<vector<bool>> graph(nodes_count, vector<bool>(nodes_count, false));
    char symbol; 

    for (int row = 0; row < nodes_count; row++) {
        for (int col = 0; col < nodes_count; col++) {
            file.get(symbol);
            if (symbol == '1') {
                graph[row][col] = true;
            }
        }
        file.ignore(); 
    }

    return graph;
}


bool is_cycle(vector<vector<bool>> &graph, vector<int> path, int initial, int current, int times)
{
	if (current == initial && times == path.size())
		return true;


	for (int i = 0; i < path.size(); i++)
	{
		if (graph[current][i] == true && path[i] == false)
		{
			path[i] = true;
			bool result = is_cycle(graph, path, initial, i, times + 1);

			if (result == true) {
				return true;
			} else {
				path[i] = false; 
            }
		}
	}
	return false;
}


int main()
{   
    std::string filepath;
    cout << "Введите путь к файлу: ";
    cin >> filepath;
    
    std::ifstream file(filepath);
	int nodes = get_nodes_count(file);
	
	vector<vector<bool>> graph = create_graph(file, nodes);
	vector<int> path(nodes); 

	for (int i = 0; i < path.size(); i++)
	{
		path[i] = 0;
	}

	if (is_cycle(graph, path, 0, 0, 0) == 1) {
        cout << "Данный граф содержит гамильтонов цикл" << endl;
    } else {
        cout << "Гамильтонов цикл в данном графе не найден" << endl; 
    }
}