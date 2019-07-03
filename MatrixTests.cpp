#include "catch2.hpp"
#include "Matrix.hpp"

TEST_CASE("Constructors are tested", "[Matrix]")
{
    Matrix matrix1(1,1);
    REQUIRE(matrix1.toString() == "0\n");
}

