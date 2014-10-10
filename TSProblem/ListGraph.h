#pragma once


#include <string>

class ListGraph {
	int numberOfNodes;
	int numberOfEdges;
	int **graph;
	void resizeGraph(int);
public:
	ListGraph(int);
	ListGraph();
	~ListGraph();
	void loadFromFile(std::string);
	int size();
	int getPathLength(int, int);
	int overallPath(std::string);
	bool isComplete();
};