#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{	
	int rm_node, vert1, vert2, dfs_node,choise;
	GRAPH undirected("matrix.txt");
	cout << " ------------------------------------------" << endl;
	cout << " Graph is presented as an adjacency matrix:" << endl << endl;
	undirected.PRINT_M();
	choise = -1;	
		cout << " Choose the operation (PRESS '0' TO CLOSE THE APPLICATION):" << endl;
		cout << "1. Add one vertex." << endl;
		cout << "2. Remove one specific vertex." << endl;
		cout << "3. Add one specific edge." << endl;
		cout << "4. Remove one specific edge." << endl;
		cout << "5. Make and print a depth-first-search starting from 1 specific vertex." << endl;
		cout << "6. Print current adjacency matrix." << endl;
		while (choise!=0) {
		cin >> choise;
		switch (choise) {
		case 1:
		{
			cout << endl;
			undirected.ADD_VERTICE();
			undirected.PRINT_M();
			break;
		}
		case 2:
		{
			cout << endl << "Enter the vertex you want remove:" << endl;
			cin >> rm_node;
			cout << endl;
			undirected.RM_VERTICE(rm_node);
			undirected.PRINT_M();
			break;
		}
		case 3:
		{
			cout << endl << "Enter two vertices you want to link:" << endl;
			cin >> vert1;
			cin >> vert2;
			cout << endl;
			undirected.ADD_EDGE(vert1, vert2);
			undirected.PRINT_M();
			break;
		}
		case 4:
		{
			cout << endl << "Enter two vertices you want to unlink:" << endl;
			cin >> vert1;
			cin >> vert2;
			cout << endl;
			undirected.RM_EDGE(vert1, vert2);
			undirected.PRINT_M();
			break;
		}
		case 5:
		{
			cout << endl << "Enter the vertex from which you want to start DFS:" << endl;
			cin >> dfs_node;
			cout << endl;
			undirected.DFS_TREE(dfs_node - 1);
			undirected.PRINT_DFS();
			break;
		}
		case 6:
		{
			cout << endl << "Current state of graph:" << endl;
			undirected.PRINT_M();
			break;
		}
		default:
		{
			cout << endl;
			system("pause");
		}
		}
	}


}