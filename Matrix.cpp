/*
 * Matrix.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Lam Duong
 */

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include <string>
#include <sstream>		/* parsing integers */
#include <stdlib.h>     /* rand */
#include <time.h> 		/* for rand seed */
#include "Matrix.hpp"

// Matrix default constructor creating a 5x5 matrix filled with 0's
Matrix::Matrix()
{
	this->amountOfColumns = 5;
	this->amountOfRows = 5;
	this->amountOfElements = 25;

	// Populating the matrix with 0's
	for (int i = 0; i < 5; i++)
	{
		std::vector<float> emptyRow(5,0);
		this->rows.push_back(emptyRow);
	}
}

// Matrix overloading cconstructor that takes in 2 ints (row, column)
Matrix::Matrix(int amountOfRows, int amountOfColumns)
{
	if ((amountOfRows == 0) || (amountOfColumns == 0))
	{
		throw std::invalid_argument("You cannot have 0 row or 0 column in a matrix");
	}
	this->amountOfColumns = amountOfColumns;
	this->amountOfRows = amountOfRows;
	this->amountOfElements = amountOfColumns * amountOfRows;
	// Populating the matrix with 0's 
	for (int i = 0; i < amountOfRows; i++)
	{
		std::vector<float> emptyRow(amountOfColumns, 0);
		this->rows.push_back(emptyRow);
	}
}

/*
 * Function: populateMatrix()
 * Parameters: none
 * Return: void
 * Author: Lam Duong
 * Description: This member function will populate the matrix via the console.
				NOTE: DO NOT use this function in GUI unless there's a good way
				about in doing so.
 */
void Matrix::populateMatrix()
{
	std::string input;
	int amountOfElements = this->amountOfElements;
	int amountOfRows = this->amountOfRows;
	int amountOfColumns = this->amountOfColumns;
	int counter = 0;

	// For iterating over the matrix and insertion of values
	int currentRow = 0;
	int currentColumn = 0;
	
	std::cout << "Please enter your data (enter 'C' without quotations to cancel): ";
	while (counter < amountOfElements)
	{
		std::cin >> input;
		if (input == "C")
		{
			std::cout << "MATRIX POPULATING CANCELED. Depopulating..." << std::endl;
			if (counter != 0)
			{
				this->depopulateMatrix();
			}
			break;
		}
		else if (inputIsInteger(input))
		{	
			std::stringstream parsing(input);
			float parsedInteger = 0;
			parsing >> parsedInteger;

			this->rows[currentRow][currentColumn] = parsedInteger;
			if (currentColumn < amountOfColumns-1)
			{
				currentColumn++;
			}
			else
			{
				currentColumn = 0;
				currentRow++;
			}
			
			std::cout << "Current matrix so far: " << std::endl;
			counter++;
			this->printMatrix();
			
			if (counter == amountOfElements)
			{
				std::cout <<  "MATRIX POPULATING PROCESS COMPLETE.";
			}
			else
			{
				std::cout << "Please enter your next integer: ";
			}
		}
		else
		{
			std::cout << "Please enter an integer value: ";
		}
	}
}
/*
 * Function: randomizeMatrix()
 * Return: void
 * Author: Lam Duong
 * Description: Populate the matrix with random numbers generated
				by an RNG with a seed of the seconds that have passed
				since 01/01/1970
 */
void Matrix::randomizeMatrix()
{
	srand (time(NULL)); // random seed every second
	int randomInteger;
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			randomInteger = rand() % 10;
			this->rows[i][j] = float(randomInteger);
		}
	}
}

/*
 * Function: isEchelonForm()
 * Return: boolean
 * Author: Lam Duong
 * Description: This member function will check if the current matrix
 * 				is in the echelon form. Return true if so. False if not so.
 * 				NOTE: This may not be the most optimized way to go about checking
 * 				for echelon form. Find a better way in your own time?
 */
bool Matrix::isEchelonForm()
{
	bool isEchelonForm = true;
	int currentPivotColumn = -1;
	for (int rowIndex = 0; rowIndex < amountOfRows; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < amountOfColumns; columnIndex++)
		{
			if (this->rows[rowIndex][columnIndex] != 0)
			{	
				// If it's a a non-zero entry before or on the current pivot column, return false
				if (columnIndex <= currentPivotColumn)
				{
					isEchelonForm = false;
					goto endOfCheck;
				}
				else if (columnIndex > currentPivotColumn)
				{
					currentPivotColumn = columnIndex;
					break;
				}
			}

			// If last column and is still 0 , this means this is a zero row.
			// Set pivot column to amountOfColumns + 1 so that if there's a new non-zero
			// row, it will return false
			if ((columnIndex == amountOfColumns-1) && (this->rows[rowIndex][columnIndex] == 0))
			{
				currentPivotColumn = amountOfColumns + 1;
			}
		}
		endOfCheck:
			break;
	}
	return isEchelonForm;
}

/*
 * Function: echelonForm()
 * Parameters:  none
 * Return: void
 * Author: Lam Duong
 * Description: this member function will rearrange the referenced matrix
 * 				to a matrix in an echelon form. The comments in the function member
 * 				contain the steps for the algorithm.
 */
void Matrix::echelonForm()
{
	if (this->isEchelonForm() == false)
	{
		//-----------------------FORWARD PHASE-----------------------------------

		/*							STEP 1:
		1) Begin with the leftmost nonzero column. This is a pivot column.
		The pivot position should be at the top.
		*/
		
		// Find the leftmost nonzero column
		int leftMostColumn = amountOfColumns; // set left-most column to the last column initially
		std::vector<std::vector<float>> pivotRows;
		std::vector<int> pivotRowIndices;
		for (int rowIndex = 0; rowIndex < amountOfRows; rowIndex++)
		{
			for (int columnIndex = 0; columnIndex < amountOfColumns; columnIndex++)
			{
				if ((rows[rowIndex][columnIndex] != 0) && (columnIndex < leftMostColumn))
				{
					leftMostColumn = columnIndex;
					pivotRows.push_back(rows[rowIndex]);
					pivotRowIndices.push_back(rowIndex);
				}
			}
		}
		// Determine one row to be the pivot row
		std::vector<float> pivotRow;
		for (int rowIndex = 0; rowIndex < pivotRows.size(); rowIndex++)
		{
			
		}
		// Move row tha row to the top

		/*							STEP 2:
		2) Select a nonzero entry in the pivot column as a pivot. If necessary,
		interchange rows to move this entry into the pivot position.
		*/
		/*
		3) Use row addition operations to create zeros in all positions below the pivot.
		*/
		
		/*
		4) Cover (or ignore) the row containing the pivot position and cover
		all rows, if any, above it. apply steps 1-3 to the submatrix that remains.
		Repeat the process until there are no more nonzero rows to modify.
		*/

		//---------------------------BACKWARD PHASE-----------------------------

		/*
		Beginning with the rightmost pivot and working upward and to the left,
		create zeros above each pivot. If a pivot is not 1, make it 1 by a scaling operation.
		*/
	}
}

/*
 * Function: rowReduction()
 * Parameters: 	(vector, vector, int, int)
 * Return: vector
 * Author: Lam Duong
 * Description: This member function will add the multiple of the first row
 * 				to the second row for row reduction. This member function should
 * 				copy the values of the rows, so that if addition cannot be done,
 * 				then the changes are then reverted. Make sure that the index
 * 				is the place where addition would start. If adding the entire row,
 * 				enter '0'.
 */
std::vector<float> Matrix::rowReduction(std::vector<float> row1, std::vector<float>row2, int index)
{
	if (row1.size() != row2.size())
	{
		throw std::invalid_argument("Cannot have two rows that are not the same size");
	}
	std::vector<float> resultingVector = row2;
	int multiple = -(row2[index]) / row1[index];
	for (int rowIndex = index; rowIndex < row2.size(); rowIndex++)
	{
		int resultingAddition = (row1[rowIndex] * multiple) + row2[rowIndex];
		resultingVector[index] = float(resultingAddition);
	}
	return resultingVector;
}

/*
 * Function: inputIsInteger()
 * Parameters: string
 * Return: boolean
 * Author: Lam Duong
 * Description: Check if the input (which is a string) is an integer.
 * 				This member fucntion is used by populateMatrix().
 */
bool Matrix::inputIsInteger(std::string input)
{
	bool isInteger = true;
	for (int i = 0; i < input.length(); i++)
	{
		if ((input[i] < 48) || (input[i] > 57)) 
		{
			isInteger = false;
			break;
		}
	}
	return isInteger;
}

/*
 * Function: depopulateMatrix()
 * Parameters: none
 * Return: void
 * Author: Lam Duong
 * Description: This function will depopulate a matrix by returning it to its
				original state with 0's.
 */
void Matrix::depopulateMatrix()
{
	int amountOfRows = this->amountOfRows;
	int amountOfColumns = this->amountOfColumns;
	// Populating the matrix with 0's 
	for (int i = 0; i < amountOfRows; i++)
	{
		std::vector<float> emptyRow(amountOfColumns, 0);
		this->rows[i] = emptyRow;
	}
}

/*
 * Function: printMatrix()
 * Parameters: none
 * Return: void
 * Author: Lam Duong
 * Description: This method simply print the matrix out onto a console.
 *				Useful for early development. WARNING: Potential dead code.
 */
void Matrix::printMatrix()
{
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			if (j == this->amountOfColumns-1)
			{
				std::cout << this->rows.at(i).at(j) << std::endl;
			}
			else
			{
				std::cout << this->rows.at(i).at(j);
				std::cout << " ";
			}
		}
	}
}

/*
* Function: toString()
* Parameters: none
* Return: string
* Author: Lam Duong
* Description:	Simply turn the matrix into a string representation. Used
*				for debugging and testing purposes. This method currently
				will only return an unformatted matrix.
				TODO: Implement a toString method where 
*/
std::string Matrix::toString()
{
	std::string stringOfMatrix;
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			if (j == this->amountOfColumns - 1)
			{
				stringOfMatrix.append(std::to_string(this->rows[i][j]));
				stringOfMatrix.append("\n");
			}
			else
			{
				stringOfMatrix.append(std::to_string(this->rows[i][j]));
				stringOfMatrix.append(" ");
			}
		}
	}
	return stringOfMatrix;
}

/* ACCESSOR MEMBER FUNCTIONS */
int Matrix::getAmountOfRows()
{
	return this->amountOfRows;
}

int Matrix::getAmountOfColumns()
{
	return this->amountOfColumns;
}