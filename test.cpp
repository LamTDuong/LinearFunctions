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
TEST(EmptyMatrixConstructorTests, MatrixConstructorTests) {
	Matrix matrix1(1, 1);
	Matrix matrix2(2, 1);
	Matrix matrix3(1, 2);
	Matrix matrix4(3, 3);
	EXPECT_EQ(matrix1.toString(), "0\n");
	EXPECT_EQ(matrix2.toString(), "0\n0\n");
	EXPECT_EQ(matrix3.toString(), "0 0\n");
	EXPECT_EQ(matrix4.toString(), "0 0 0\n0 0 0\n0 0 0\n");
}

TEST(EmptySecondTest, AnotherTest)
{
	EXPECT_TRUE(true);
}