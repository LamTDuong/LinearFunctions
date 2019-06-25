#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Matrix.h"

TEST_CASE("Just an empty 1x1 matrix", "[single-file]") {
	Matrix matrix1(1, 1);
	matrix1.populateMatrix();
	REQUIRE(matrix1.toString() == "0");
}