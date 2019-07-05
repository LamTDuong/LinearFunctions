#include "catch2.hpp"
#include "Matrix.hpp"

TEST_CASE("Constructors are tested", "[Matrix]")
{
    Matrix matrix1(1, 1);
	Matrix matrix2(2, 1);
	Matrix matrix3(1, 2);
	Matrix matrix4(3, 3);
	Matrix matrix5(12, 20);
	Matrix matrix6;
    REQUIRE(matrix1.toString() == "0\n");
}

