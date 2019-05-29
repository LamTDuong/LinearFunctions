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
    Matrix();
    Matrix(int amountOfRows, int amountOfColumns);
    void populateMatrix();
    void printMatrix();
    void emptyMatrix();
private:
    std::vector<std::vector<int>> rows;
    int amountOfRows;
    int amountOfColumns;
    int amountOfElements;
};

#endif /* MATRIX_H_ */
