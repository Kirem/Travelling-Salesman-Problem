// TSProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SimmulatedAnnealing.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SimmulatedAnnealing simmulation;
	string path = "..\\TSProblem\\komiwojazer1.txt";
	simmulation.loadGraphFromFile(path);
	int result = simmulation.runAlgorithm();

	return 0;
}

