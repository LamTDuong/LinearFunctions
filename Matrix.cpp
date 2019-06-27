/*
 * Matrix.cpp
 *
 *  Created on: May 27, 2019
 *      Author: Lam Duong
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>		/* parsing integers */
#include <stdlib.h>     /* rand */
#include <time.h> 		/* for rand seed */
#include "pch.h"		/* for testing purposes*/
#include "Matrix.h"

// Matrix default constructor creating a 5x5 matrix filled with 0's
Matrix::Matrix()
{
	this->amountOfColumns = 5;
	this->amountOfRows = 5;
	this->amountOfElements = 25;

	// Populating the matrix with 0's
	for (int i = 0; i < 5; i++)
	{
		std::vector<int> emptyRow(5,0);
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
		std::vector<int> emptyRow(amountOfColumns, 0);
		this->rows.push_back(emptyRow);
	}
}

// Populate the matrix with user inputs
// Calls on inputIsInteger() member function
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
			int parsedInteger = 0;
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

// Populate the matrix with random numbers
// Seed is every second
void Matrix::randomizeMatrix()
{
	srand (time(NULL)); // random seed every second
	int randomInteger;
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			randomInteger = rand() % 10;
			this->rows[i][j] = randomInteger;
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
 * 				to a matrix in an echelon form
 */
void Matrix::echelonForm()
{
	while (this->isEchelonForm() == false)
	{
		for (int rowIndex = 0; rowIndex < this->amountOfRows; rowIndex++)
		{

		}
	}
}

/*
 * Function: rowAddition()
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
std:vector<int> Matrix::rowReduction(std::vector<int> row1, std::vector<int>row2, int index)
{
	if (row1.size() != row2.size())
	{
		// TODO: throw error: need both vectors to have the same size
	}
	std::vector<int> resultingVector = row2;
	int multiple = -(row2[index]) / row1[index];
	for (int rowIndex = index; rowIndex < row2.size(); rowIndex++)
	{
		int resultingAddition = (row1[rowIndex] * multiple) + row2[rowIndex];
		resultingVector[index] = resultingAddition;
	}
	return resultingVector;
}

// Check if the string is an integer
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

// Empty the matrix by entering zeros into everything
void Matrix::depopulateMatrix()
{
	int amountOfRows = this->amountOfRows;
	int amountOfColumns = this->amountOfColumns;
	// Populating the matrix with 0's 
	for (int i = 0; i < amountOfRows; i++)
	{
		std::vector<int> emptyRow(amountOfColumns, 0);
		this->rows[i] = emptyRow;
	}
}

// Printing for debugging
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
* Description: Simply turn the matrix into a string representation.
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

int main()
{
	Matrix matrix1(1, 1);
	return 0;
}