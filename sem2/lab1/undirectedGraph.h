#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <map>

class Ngraph {
public:
	bool VertexExists(int vertex);
	bool EdgeExists(int a, int b);

	void AddVertex(int a);
	void AddEdge(int a, int b);
	void DeleteVertex(int a);
	void DeleteEdge(int a, int b);
	void DFSTree(int first);

private:
	std::map<int, std::set<int>> graph;
	void DFS(int a, std::map<int, bool>& visited);
};