/*
 * Matrix.h
 *
 *  Created on: May 27, 2019
 *      Author: Lam Duong
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
public:
	// Constructors:
    Matrix();
    Matrix(int amountOfRows, int amountOfColumns);
	// Accessors:
	int getAmountOfRows();
	int getAmountOfColumns();
	// Mutators and others:
    void populateMatrix();
    void printMatrix();
    void depopulateMatrix();
    void randomizeMatrix();
    bool isEchelonForm();
    void echelonForm();
    void reducedEchelonForm();
    bool isReducedEchelonForm();
    std::vector<float> rowReduction(std::vector<float> row1, std::vector<float> row2, int index);
	std::string toString();
    static bool inputIsInteger(std::string input);
private:
    std::vector<std::vector<float>> rows;
    std::vector<std::vector<float>> columns; // TODO: Implement the 
    int amountOfRows;
    int amountOfColumns;
    int amountOfElements;
};

#endif /* MATRIX_H_ */
