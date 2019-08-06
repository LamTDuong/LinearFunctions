#include "catch2.hpp"
#include "Matrix.hpp"
//#include <string>

TEST_CASE("Constructors are tested", "[Matrix]")
{
	Matrix matrix1(1, 1);
	Matrix matrix2(2, 1);
	Matrix matrix3(1, 2);
	Matrix matrix4(3, 3);
	Matrix matrix5(12, 20);
	Matrix matrix6;
	
	REQUIRE(matrix1.toString() ==  "0.000000\n");
	REQUIRE(matrix1.getAmountOfColumns() == 1);
	REQUIRE(matrix1.getAmountOfRows() == 1);
	
	REQUIRE(matrix2.toString() == "0.000000\n0.000000\n");
	REQUIRE(matrix2.getAmountOfColumns() == 1);
	REQUIRE(matrix2.getAmountOfRows() == 2);

	REQUIRE(matrix3.toString() == "0.000000 0.000000\n");
	REQUIRE(matrix3.getAmountOfColumns() == 2);
	REQUIRE(matrix3.getAmountOfRows() == 1);

	REQUIRE(matrix4.toString() == "0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000\n");
	REQUIRE(matrix4.getAmountOfColumns() == 3);
	REQUIRE(matrix4.getAmountOfRows() == 3);
	

	/*
	std::string matrix5String = "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	matrix5String += "0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000\n";
	*/
	REQUIRE(matrix5.getAmountOfColumns() == 20);
	REQUIRE(matrix5.getAmountOfRows() == 12);

	REQUIRE(matrix6.toString() == "0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n");
	REQUIRE(matrix6.getAmountOfRows() == 5);
	REQUIRE(matrix6.getAmountOfColumns() == 5);
}