
#include "../TSProblem/SimmulatedAnnealing.cpp"

#include "gtest/gtest.h"
#include <string>
using namespace std;


TEST(SimmulatedAnnealingTest, NewCreatedAlgorithmShouldNotContainGraph) {
	SimmulatedAnnealing simmulation;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	ASSERT_EQ(0 , simmulation.getProblemSize());
}

TEST(SimmulatedAnnealingTest, AfterLoadingGraphFromFileProblemSizeShouldBeKnown) {
	SimmulatedAnnealing simmulation;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	simmulation.loadGraphFromFile(path);
	ASSERT_EQ(8, simmulation.getProblemSize());
}

TEST(SimmulatedAnnealingTest, AlgorithmShouldReturnOptimaizedSolution) {
	SimmulatedAnnealing simmulation;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	simmulation.loadGraphFromFile(path);
	int result = simmulation.runAlgorithm();
	ASSERT_EQ(8, result);
}


