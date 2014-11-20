#include "stdafx.h"
#include "ListGraph.h"
#include <fstream>
#include <random>
#include "CharToIntParser.h"
#include <string>
#include <sstream>


using namespace std;
ListGraph::ListGraph(int size) {
	numberOfNodes = size;
	numberOfEdges = numberOfNodes * (numberOfNodes-1);
	graph = new float*[numberOfNodes];
	randomInterval = make_pair(10, 100);
	for(int i = 0; i < numberOfNodes; i++) {
		graph[i] = new float[numberOfNodes];
	}
}

ListGraph::ListGraph() {
	numberOfNodes = 0;
	numberOfEdges = 0;
	graph = nullptr;
	randomInterval = make_pair(10, 100);
}

ListGraph::~ListGraph() {
	if(graph) {
		for(int i = 0; i < numberOfNodes; i++) {
			delete[] graph[i];
		}
		delete[] graph;
	}

}
int ListGraph::size() {
	return numberOfNodes;
} 

float ListGraph::overallPath(std::string path) {
	CharToIntParser parser;

	int* nodes = parser.parse(path);
	int size = path.size();
	float pathLength = 0;
	for(int i = 0; i < size-1; i++){
		pathLength += graph[nodes[i]][nodes[i+1]];
	}
	pathLength += graph[nodes[size-1]][nodes[0]];
	delete[] nodes;
	return pathLength;
}

void ListGraph::loadFromFile(std::string path) {
	std::fstream graphToLoad(path, std::ios::in);
	if(graphToLoad.fail()) {
		throw new std::exception("File not found");
	}
	int numberOfNodes;
	int numberOfEdges = 0;
	string checker;
	graphToLoad >> checker;
	if(checker.compare("NAME:") == 0) {
		loadSymetricTestGraph(graphToLoad);
	} else {
		std::istringstream stream(checker);
		int size;
		stream >> size;
		loadGraph(graphToLoad, size);
	}


	graphToLoad.close();
}

void ListGraph::loadGraph(std::istream &str, int size) {
	resizeGraph(numberOfNodes);
	this->numberOfNodes = size;

	for(int i = 0; i < numberOfNodes; i++) {
		int length;
		for(int j = 0; j < numberOfNodes; j++) {
			str >> length;
			graph[i][j] = length;
			if(length > 0)
				numberOfEdges++;
		}
	}
	this->numberOfEdges = numberOfEdges;
}

void ListGraph::loadSymetricTestGraph(std::istream& stream) {
	string s;
	while(s.compare("DIMENSION:") != 0) {
		stream >> s;
	}
	int size;
	stream >> size;
	this->numberOfNodes = size;
	resizeGraph(size);
	while(s.compare("EDGE_WEIGHT_SECTION") != 0) {
		stream >> s;
	}
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < i + 1; j++) {
			int value;
			stream >> value;
			graph[i][j] = graph[j][i] = value;
		}
	}
}

void ListGraph::createRandomGraph(int size) {
	random_device device;
	uniform_int_distribution<int> distribution(randomInterval.first, randomInterval.second);
	numberOfNodes = size;
	numberOfEdges = 0;
	resizeGraph(numberOfNodes);

	for(int i = 0; i < numberOfNodes; i++) {
		for(int j = i; j < numberOfNodes; j++) {
			if(j==i) {
				graph[i][j] = 0;
				continue;
			}

			int pathValue = distribution(device);
			graph[i][j] = graph[j][i] = pathValue;
			numberOfEdges++;
		}
	}
}

void ListGraph::resizeGraph(int newSize) {
	if(graph) {
		for(int i = 0; i < numberOfNodes; i++) {
			delete[] graph[i];
		}
		delete[] graph;
	}
	graph = new float*[newSize];
	for(int i = 0; i < newSize; i++) {
		graph[i] = new float[newSize];
	}
}

float ListGraph::getPathLength(int startNode, int endNode) {
	return graph[startNode][endNode];
}


bool ListGraph::isComplete() {
	int maxNumberOfEdges = numberOfNodes*(numberOfNodes-1);
	return maxNumberOfEdges == numberOfEdges;
}

void ListGraph::print(std::ostream& output) {
	for(int i = 0; i < numberOfNodes; i++) {
		for(int j = 0; j < numberOfNodes; j++) {
			output << graph[i][j] <<" ";
		}
		output << std::endl;
	}
	output << std::endl;
}