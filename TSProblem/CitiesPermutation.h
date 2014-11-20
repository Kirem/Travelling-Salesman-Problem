#pragma once
#include<string>
using namespace std;
class CitiesPermutation {
	string permutation;
public:
	CitiesPermutation();
	CitiesPermutation(int);
	CitiesPermutation(CitiesPermutation&);
	virtual ~CitiesPermutation() {}
	string toString();
	int size();
	void swapCities(int, int);
	void permute();
	void randomPermutation();
	CitiesPermutation& operator=(const CitiesPermutation& p);
};