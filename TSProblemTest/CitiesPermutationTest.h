
#include "../TSProblem/CitiesPermutation.cpp"

#include "gtest/gtest.h"
#include <string>
using namespace std;
TEST(CitiesPermutationTests, NewPermutationShouldHaveFixedSize) {
	CitiesPermutation perm(5);
	ASSERT_EQ(5, perm.size());
}

TEST(CitiesPermutationTests, NewPermutationShouldContainEveryCity) {
	CitiesPermutation perm(3);
	string s = perm.toString();
	ASSERT_FALSE(s.find('A') == string::npos);
	ASSERT_FALSE(s.find('B') == string::npos);
	ASSERT_FALSE(s.find('C') == string::npos);
}

TEST(CitiesPermutationTests, AfterSinglePermutationOrderShouldchange) {
	CitiesPermutation perm(3);
	string s1 = perm.toString();
	perm.permute();
	string s2 = perm.toString();
	ASSERT_NE(s1, s2);
}

TEST(CitiesPermutationTests, SwapShouldSwap2Cities) {
	CitiesPermutation perm(3);
	string s1 = perm.toString();
	perm.swapCities(1,2);
	string s2 = perm.toString();
	ASSERT_NE(s1, s2);
	ASSERT_FALSE(s2.find('A') == string::npos);
	ASSERT_FALSE(s2.find('B') == string::npos);
	ASSERT_FALSE(s2.find('C') == string::npos);
}

TEST(CitiesPermutationTests, ShouldThrowExceptionWhenWhenSwapWithPermutationContainsLessThen2Cities_OR_IndexOutOfRange) {
	CitiesPermutation perm(1);
	ASSERT_ANY_THROW(perm.swapCities(0, 1));
	ASSERT_ANY_THROW(perm.swapCities(0, 5));
	ASSERT_ANY_THROW(perm.swapCities(-1, 5));
}

TEST(CitiesPermutationTests, ShouldBeAbleToCreateRandomPermutation) {
	CitiesPermutation perm(3);
	perm.randomPermutation();
	ASSERT_FALSE(perm.toString().find('A') == string::npos);
	ASSERT_FALSE(perm.toString().find('B') == string::npos);
	ASSERT_FALSE(perm.toString().find('C') == string::npos);
}
