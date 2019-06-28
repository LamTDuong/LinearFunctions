/*
 * TITLE: Automated Unit Tests for LineFunc
 * AUTHOR: LAM DUONG
 * DESCRIPTION: These unit tests are only made to run on Visual Studio 2019
 *				with the correct environment setup. You will need to have a
 *				VS Windows Application project and Google Tests in order to
 *				run these test cases. Contact Lam Duong for more information.
*/

#include "pch.h"
#include "../LinearFunctions/Matrix.hpp"
#include "../LinearFunctions/Matrix.cpp"

/*
* DESCRIPTION: Test empty matrices and see if their string outputs are correct
* TODO: In the future, there might be a new toString() member function that will
*		make the expected outputs of these test cases obsolete.
*/
TEST(InitialMatrixConstructorTests, MatrixConstructorTests) {
	Matrix matrix1(1, 1);
	Matrix matrix2(2, 1);
	Matrix matrix3(1, 2);
	Matrix matrix4(3, 3);
	Matrix matrix5(12, 20);
	Matrix matrix6;
	
	EXPECT_THROW(Matrix matrix7(0, 0), std::invalid_argument);

	EXPECT_EQ(matrix1.toString(), "0\n");
	EXPECT_EQ(matrix1.getAmountOfColumns(), 1);
	EXPECT_EQ(matrix1.getAmountOfRows(), 1);

	EXPECT_EQ(matrix2.toString(), "0\n0\n");
	EXPECT_EQ(matrix2.getAmountOfColumns(), 1);
	EXPECT_EQ(matrix2.getAmountOfRows(), 2);

	EXPECT_EQ(matrix3.toString(), "0 0\n");
	EXPECT_EQ(matrix3.getAmountOfColumns(), 2);
	EXPECT_EQ(matrix3.getAmountOfRows(), 1);

	EXPECT_EQ(matrix4.toString(), "0 0 0\n0 0 0\n0 0 0\n");
	EXPECT_EQ(matrix4.getAmountOfColumns(), 3);
	EXPECT_EQ(matrix4.getAmountOfRows(), 3);

	EXPECT_EQ(matrix5.toString(), "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
	EXPECT_EQ(matrix5.getAmountOfColumns(), 20);
	EXPECT_EQ(matrix5.getAmountOfRows(), 12);

	EXPECT_EQ(matrix6.toString(), "0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n");
	//EXPECT_EQ(matrix6.getAmountOfRows, 5);
	//EXPECT_EQ(matrix6.getAmountOfColumns, 5);
}

TEST(EmptySecondTest, AnotherTest)
{	
	EXPECT_TRUE(true);
}