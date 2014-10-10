#include "CitiesPermutation.h"
#include "stdafx.h"
#include <random>

CitiesPermutation::CitiesPermutation(int numberOfCities) {
	char temp = 'A';

	for(int i = 0; i < numberOfCities; i++) {
		permutation += temp;
		temp++;
	}
	if(numberOfCities > 1) {
		for(int i = 0; i < numberOfCities; i++) {
			permute();
		}
	}
}

CitiesPermutation::CitiesPermutation() {
	permutation = "";
}

string CitiesPermutation::toString() {
	return permutation;
}

int CitiesPermutation::size() {
	return permutation.size();
}

void CitiesPermutation::permute() {
	random_device device;
	uniform_int_distribution<int> dist(0, permutation.size()-1);
	
	int index1 = 0;
	int index2 = 0;
	while(index1 == index2) {
		index1 = dist(device);
		index2 = dist(device);
	}
	swapCities(index1, index2);
}

void CitiesPermutation::swapCities(int ind1, int ind2) {
	if(ind1 >= permutation.size() || ind2 >= permutation.size()
			|| ind1 < 0 || ind2 < 0) {
		throw new exception("index error");
	}

	char c = permutation[ind1];
	permutation[ind1] = permutation[ind2];
	permutation[ind2] = c;
}


void CitiesPermutation::randomPermutation() {
	for(int i = 0; i < permutation.size(); i++) {
		permute();
	}
}

CitiesPermutation& CitiesPermutation::operator=(const CitiesPermutation& p) {
	this->permutation = p.permutation;
	return *this;
}
