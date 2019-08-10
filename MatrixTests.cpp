#include "catch2.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <chrono>

TEST_CASE("Constructor tests")
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
	REQUIRE(matrix5.toString() == matrix5String);
	REQUIRE(matrix5.getAmountOfColumns() == 20);
	REQUIRE(matrix5.getAmountOfRows() == 12);

	REQUIRE(matrix6.toString() == "0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n0.000000 0.000000 0.000000 0.000000 0.000000\n");
	REQUIRE(matrix6.getAmountOfRows() == 5);
	REQUIRE(matrix6.getAmountOfColumns() == 5);
}

// NOTE: Test case running randomize matrix function 4 times that wait
// for 1 second each. With 2 randomize functions, expect test to run for 8 seconds.

TEST_CASE("Randomize Matrix Tests")
{
	Matrix matrix1(1, 1);
	Matrix matrix2(2, 1);
	Matrix matrix3(12, 20);
	Matrix matrix4;

	std::string matrix1OriginalString = matrix1.toString();
	matrix1.randomizeMatrix();
	std::string matrix1RandomizedString = matrix1.toString();
	REQUIRE(matrix1OriginalString != matrix1RandomizedString);
	matrix1.randomizeMatrix();
	std::string matrix1NewRandomizedString = matrix1.toString();
	REQUIRE(matrix1RandomizedString != matrix1NewRandomizedString);
	REQUIRE(matrix1OriginalString != matrix1NewRandomizedString);

	std::string matrix2OriginalString = matrix2.toString();
	matrix2.randomizeMatrix();
	std::string matrix2RandomizedString = matrix2.toString();
	REQUIRE(matrix2OriginalString != matrix2RandomizedString);
	matrix2.randomizeMatrix();
	std::string matrix2NewRandomizedString = matrix2.toString();
	REQUIRE(matrix2RandomizedString != matrix2NewRandomizedString);
	REQUIRE(matrix2OriginalString != matrix2NewRandomizedString);

	std::string matrix3OriginalString = matrix3.toString();
	matrix3.randomizeMatrix();
	std::string matrix3RandomizedString = matrix3.toString();
	REQUIRE(matrix3OriginalString != matrix3RandomizedString);
	matrix3.randomizeMatrix();
	std::string matrix3NewRandomizedString = matrix3.toString();
	REQUIRE(matrix3RandomizedString != matrix3NewRandomizedString);
	REQUIRE(matrix3OriginalString != matrix3NewRandomizedString);

	std::string matrix4OriginalString = matrix4.toString();
	matrix4.randomizeMatrix();
	std::string matrix4RandomizedString = matrix4.toString();
	REQUIRE(matrix4OriginalString != matrix4RandomizedString);
	matrix4.randomizeMatrix();
	std::string matrix4NewRandomizedString = matrix4.toString();
	REQUIRE(matrix4RandomizedString != matrix4NewRandomizedString);
	REQUIRE(matrix4OriginalString != matrix4NewRandomizedString);
}

TEST_CASE("isEchelonForm() Tests")
{
	/* Populating a matrix that looks like this:
	 *	1 0 2 3 4
	 *	0 1 5 6 7
	 *	0 0 0 1 8
	 * 	0 0 0 0 1 */
	Matrix matrix1;
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(4),0,4);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(3),0,3);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(2),0,2);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(7),1,4);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(6),1,3);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(5),1,2);
	REQUIRE(matrix1.isEchelonForm() == false);
	matrix1.insertAt(float(1),1,1);
	REQUIRE(matrix1.isEchelonForm() == false);
	matrix1.insertAt(float(1),0,0);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(1),3,4);
	REQUIRE(matrix1.isEchelonForm() == false);
	matrix1.insertAt(float(8),2,4);
	REQUIRE(matrix1.isEchelonForm() == false);
	matrix1.insertAt(float(1),2,3);
	REQUIRE(matrix1.isEchelonForm() == true);
	matrix1.insertAt(float(11),3,0);
	REQUIRE(matrix1.isEchelonForm() == false);
	matrix1.insertAt(float(0),3,0);
	REQUIRE(matrix1.isEchelonForm() == true);
	//std::string matrixString = matrix1.toString();
	//std::cout << matrixString;
}

TEST_CASE("Row Reduced Tests")
{
	
}