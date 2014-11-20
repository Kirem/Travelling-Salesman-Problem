#pragma once


#include <string>
#include <ostream>
#include <istream>
class ListGraph {
	int numberOfNodes;
	int numberOfEdges;
	float **graph;
	void resizeGraph(int);
	std::pair<int, int> randomInterval;
	void loadSymetricTestGraph(std::istream& s);
	void loadAsymetricTestGraph(std::istream& s);
	void loadGraph(std::istream& s, int);
public:
	ListGraph(int);
	ListGraph();
	~ListGraph();
	void loadFromFile(std::string);
	void createRandomGraph(int);
	int size();
	float getPathLength(int, int);
	float overallPath(std::string);
	bool isComplete();
	void  print(std::ostream&);
};