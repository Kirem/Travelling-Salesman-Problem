#include "stdafx.h"
#include "ListGraph.h"
#include <fstream>
#include <iostream>
#include "CharToIntParser.h"

ListGraph::ListGraph(int size) {
	numberOfNodes = size;
	numberOfEdges = numberOfNodes * (numberOfNodes-1);
	graph = new float*[numberOfNodes];
	for(int i = 0; i < numberOfNodes; i++) {
		graph[i] = new float[numberOfNodes];
	}
}

ListGraph::ListGraph() {
	numberOfNodes = 0;
	numberOfEdges = 0;
	graph = nullptr;
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
	graphToLoad >> numberOfNodes;

	resizeGraph(numberOfNodes);
	this->numberOfNodes = numberOfNodes;

	for(int i = 0; i < numberOfNodes; i++) {
		int length;
		for(int j = 0; j < numberOfNodes; j++) {
			graphToLoad >> length;
			graph[i][j] = length;
			if(length > 0)
				numberOfEdges++;
		}
	}
	this->numberOfEdges = numberOfEdges;
	graphToLoad.close();
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