// TSProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SimmulatedAnnealing.h"
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	SimmulatedAnnealing simmulation;
	string path = "..\\TSProblem\\komiwojazer3.txt";
	simmulation.loadGraphFromFile(path);
	int result = simmulation.runAlgorithm();
	cout << endl<<endl<<result<<endl;
	getchar();
	return 0;
}

