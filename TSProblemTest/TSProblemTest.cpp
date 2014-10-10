// TSProblemTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include <conio.h>

#include "../TSProblem/SimmulatedAnnealing.h"
#include "CitiesPermutationTest.h"
#include "ListGraphTest.h"
#include "CharToIntParserTest.h"
#include "SimmulatedAnnealingTest.h"

TEST(SimmulatedAnnealingTest, foo) {
	SimmulatedAnnealing sim;
	ASSERT_EQ(1, sim.add());
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}

