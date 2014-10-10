#pragma once
#include "../TSProblem/CharToIntParser.cpp"

#include "gtest/gtest.h"
#include <string>
using namespace std;


TEST(CharToIntTest, EmptyStringShouldThrowException) {
	CharToIntParser p;
	int* tab = nullptr;
	ASSERT_ANY_THROW(tab = p.parse(""));
	if(tab) {
		delete [] tab;
	}
}

TEST(CharToIntTest, singleLettersShouldParseToProperIntegers) {
	CharToIntParser p;
	int* tab;
	tab = p.parse("A");
	ASSERT_EQ(0, tab[0]);
	delete[] tab;
	tab = p.parse("B");
	ASSERT_EQ(1, tab[0]);
	delete[] tab;
	tab = p.parse("C");
	ASSERT_EQ(2, tab[0]);
	delete[] tab;
}

TEST(CharToIntTest, longerStringsShouldParseToProperIndexForEachLetter) {
	CharToIntParser p;
	int* tab;
	tab = p.parse("ACDBA");
	ASSERT_EQ(0, tab[0]);
	ASSERT_EQ(2, tab[1]);
	ASSERT_EQ(3, tab[2]);
	ASSERT_EQ(1, tab[3]);
	delete[] tab;

}
