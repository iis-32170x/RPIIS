#pragma once
#include <stdexcept>
#include <vector>
#include <set>
#include <map>

class Ngraph {
public:

	std::map<int, std::set<int>> graph;
    void AddVertex(int a);
    void AddEdge(int a, int b);
	void DeleteVertex(int a);
	void printGraph();
	void DeleteEdge(int a, int b);
	void DFSTree(int first);

private:

	void DFS(int a, std::map<int, bool>& visited);
	

};
