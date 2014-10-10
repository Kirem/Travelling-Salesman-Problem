
#include "../TSProblem/ListGraph.cpp"

#include "gtest/gtest.h"
#include <string>
using namespace std;



TEST(ListGraphTest, SizeShouldReturnNumberOfNodes) {
	ListGraph graph(5);
	ASSERT_EQ(5, graph.size());
}

TEST(ListGraphTest, AfterLoadingGraphFromFilePathsShouldBeKnown) {
	ListGraph graph;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	graph.loadFromFile(path);
	ASSERT_EQ(8, graph.size());
	ASSERT_EQ(4, graph.getPathLength(0, 1));
}

TEST(ListGraphTest, GivenCitiesPermutationAsStringTotalPathShouldBeReturned) {
	ListGraph graph;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	graph.loadFromFile(path);
	int length = graph.overallPath("ABFCDEHG");
	ASSERT_EQ(23, length);
	
}

TEST(ListGraphTest, GraphShouldIndicatteCorrectlyIfIsComplete) {
	ListGraph graph;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	graph.loadFromFile(path);
	ASSERT_EQ(false, graph.isComplete());
}