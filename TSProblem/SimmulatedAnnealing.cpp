#include "stdafx.h"
#include "SimmulatedAnnealing.h"
#include <random>
#include <iostream>

SimmulatedAnnealing::SimmulatedAnnealing() {
	size = 0;
	graph = nullptr;
}

SimmulatedAnnealing::SimmulatedAnnealing(ListGraph* g) {
	size = g->size();
	graph = g;
}

SimmulatedAnnealing::~SimmulatedAnnealing() {
	if(graph) {
		delete graph;
	}
}

int SimmulatedAnnealing::add() {
	return 1;
}

int SimmulatedAnnealing::getProblemSize() {
	return size;
}

void SimmulatedAnnealing::loadGraphFromFile(string path) {
	if(graph)
		delete graph;
	
	graph = new ListGraph();
	graph->loadFromFile(path);
	this->size = graph->size();
	CitiesPermutation perm(size);
	permutation = perm;
}

void SimmulatedAnnealing::createRandomGraph(int size) {
	if(graph)
		delete graph;

	graph = new ListGraph();
	graph->createRandomGraph(size);
	this->size = graph->size();
	CitiesPermutation perm(size);
	permutation = perm;
}

void SimmulatedAnnealing::printGraph(std::ostream& out) {
	graph->print(out);
}

int SimmulatedAnnealing::runAlgorithm() {
	float actualPoint = findStartingPoint();
	float bestKnownAnswer, currentAnswer;
	permutation.randomPermutation();
	string bestPermutation;
	currentAnswer = bestKnownAnswer = graph->overallPath(permutation.toString());
	
	random_device dev;
	uniform_real_distribution<> dist(0, 1);
	while(actualPoint > this->minimalTemp) {
		CitiesPermutation tempPermutation = permutation;
		tempPermutation.permute();
		int tempAnswer = graph->overallPath(tempPermutation.toString());
		if(tempAnswer < currentAnswer) {
			currentAnswer = tempAnswer;
			permutation = tempPermutation;
			if(tempAnswer < bestKnownAnswer) {
				bestKnownAnswer = tempAnswer;
				bestPermutation = permutation.toString();
			}
		} else if(dist(dev) < stepProbability(currentAnswer, tempAnswer, actualPoint)) {
			currentAnswer = tempAnswer;
			permutation = tempPermutation;

		}
		actualPoint *= 0.999995;
	}
	//cout << bestPermutation;
	return bestKnownAnswer;
}


float SimmulatedAnnealing::stepProbability(int result0, int result1, float actualTemp) {
	return pow(e,(-1)*(result1-result0)/actualTemp);
}

int SimmulatedAnnealing::findStartingPoint() {
	int result1 = graph->overallPath(permutation.toString());
	int result2;
	int delta = 0;
	for(int i = 0; i < size*size*size; i++) {
		permutation.randomPermutation();
		result2 = graph->overallPath(permutation.toString());
		int delta2 = result1 - result2;
		if(delta2 > delta) {
			delta = delta2;
		}
	}
	return size*size;
}