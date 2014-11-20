// TSProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SimmulatedAnnealing.h"
#include <iostream>
#include <fstream>
#include "Timer.h"
#include <sstream>
const int NUMBER_OF_SAMPLES = 4;
string files[] = {"gr17", "gr21", "gr24", "gr48"};
int optimalResults[] = {2085, 2707, 1272, 5046};

using namespace std;
float runSimulation(int, int);
SimmulatedAnnealing simmulation;

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0; i < NUMBER_OF_SAMPLES; i++) {
		simmulation.loadGraphFromFile(files[i] + ".tsp");
		float value = runSimulation(10, i);
		std::fstream data;
		stringstream s;
		s <<"data/blad-0.999995-" << files[i] << ".txt";
		data.open(s.str(), ios::trunc|ios::out);
		data << value/optimalResults[i]<<endl;
		data.close();
		cout << endl<<endl;
	}
	getchar();
	return 0;
}


float runSimulation(int numberOfTimes, int count) {
	std::fstream dataToSave;
	stringstream s;
	s <<"data/symulacja-0.999995-" << files[count] << ".txt";
	dataToSave.open(s.str(), ios::trunc|ios::out);
	int sum = 0;

	for(int i = 0; i < numberOfTimes; i++) {
		cout << i << endl;
		Timer timer;
		timer.startTimer();
		sum += simmulation.runAlgorithm();
		double time = timer.endTimer();
		dataToSave << time << " ";
	}
	dataToSave.close();
	return (float)sum/numberOfTimes;
}
