#pragma once


#include <string>
#include <ostream>
class ListGraph {
	int numberOfNodes;
	int numberOfEdges;
	float **graph;
	void resizeGraph(int);
public:
	ListGraph(int);
	ListGraph();
	~ListGraph();
	void loadFromFile(std::string);
	int size();
	float getPathLength(int, int);
	float overallPath(std::string);
	bool isComplete();
	void  print(std::ostream&);
};