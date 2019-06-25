#include "../Matrix.h"
#include "../Matrix.cpp"
#include <string>
#include "catch2.hpp"

TEST_CASE("EmptyMatrixConstructioNTests")
{
	Matrix matrix1(1, 1);
	matrix1.populateMatrix();
	REQUIRE(matrix1.toString() == "0");
}


// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success