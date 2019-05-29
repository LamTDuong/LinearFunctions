#include <iostream>
#include <vector>
#include <string>
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

// Matrix overloading constructor that takes in 2 ints (row, column)
Matrix::Matrix(int amountOfRows, int amountOfColumns)
{
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
	std::cout << "The amount of elements is: ";
	std::cout << this->amountOfElements << std::endl;
	std::cout << "The amount of rows is: ";
	std::cout << this->amountOfRows << std::endl;
	std::cout << "The amount of columns is: ";
	std::cout << this->amountOfColumns << std::endl;
}

int main()
{
	Matrix myMatrix();
	myMatrix.printMatrix();
	return 0;
}