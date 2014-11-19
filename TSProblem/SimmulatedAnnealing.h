
#pragma once

#include "CitiesPermutation.h"
#include "CharToIntParser.h"
#include "ListGraph.h"

class SimmulatedAnnealing {
	ListGraph* graph;
	int size;
	const float e = 2.71828182846;
	const float minimalTemp = 0.001;
	CitiesPermutation permutation;
	
	float stepProbability(int, int, float);
	int findStartingPoint();
public:
	SimmulatedAnnealing();
	virtual ~SimmulatedAnnealing();
	int add();
	int getProblemSize();
	void loadGraphFromFile(std::string);
	int runAlgorithm();


};