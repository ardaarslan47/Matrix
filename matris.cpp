#include "matris.h"
#include <cmath>

Matrix::Matrix(unsigned short r, unsigned short col) : column(col), row(r)
{
    content = new double *[row];
    for (int i = 0; i < row; i++)
    {
        content[i] = new double[column];
        for (int j = 0; j < column; j++)
        {
            content[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
    {
        delete[] content[i];
    }
    delete[] content;
}

void Matrix::setValue(unsigned short r, unsigned short col, double value)
{
    content[r][col] = value;
}

double Matrix::getValue(unsigned short r, unsigned short col) const
{
    return content[r][col];
}

void Matrix::display() const
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cout << getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

Matrix matrixAddition(const Matrix &a, const Matrix &b)
{
    if (a.column == b.column && a.row == b.row)
    {
        Matrix sum(a.row, a.column);

        for (int i = 0; i < sum.row; i++)
        {
            for (int j = 0; j < sum.column; j++)
            {
                double sumValue = a.getValue(i, j) + b.getValue(i, j);
                sum.setValue(i, j, sumValue);
            }
        }
        return sum;
    }
    else
    {
        std::cerr << "Error! Matrices must be on the same size.";
        return Matrix();
    }
}

Quadratic matrixAddition(const Quadratic &a, const Quadratic &b)
{
    if (a.row == b.row)
    {
        Quadratic sum(a.row);

        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.row; j++)
            {
                double sumValue = a.getValue(i, j) + b.getValue(i, j);
                sum.setValue(i, j, sumValue);
            }
        }
        return sum;
    }
    else
    {
        std::cerr << "Error! Matrices must be on the same size.";
        return Quadratic();
    }
}

Matrix Matrix::transpose() const
{
    Matrix aT(row, column);

    for (int i = 0; i < aT.row; i++)
    {
        for (int j = 0; j < aT.column; j++)
        {
            aT.setValue(i, j, getValue(j, i));
        }
    }

    return aT;
}

Quadratic Quadratic::transpose() const
{
    Quadratic aT(row);

    for (int i = 0; i < aT.row; i++)
    {
        for (int j = 0; j < aT.row; j++)
        {
            aT.setValue(i, j, getValue(j, i));
        }
    }

    return aT;
}

Matrix Matrix::multiply(double by) const
{
    Matrix multiMatrix(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            multiMatrix.setValue(i, j, getValue(i, j) * by);
        }
    }
    return multiMatrix;
}

Quadratic Quadratic::multiply(double by) const
{
    Quadratic multiMatrix(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            multiMatrix.setValue(i, j, getValue(i, j) * by);
        }
    }
    return multiMatrix;
}

Matrix matrixMultiplication(const Matrix &a, const Matrix &b)
{
    if (a.column == b.row)
    {
        Matrix multiMatrix(a.row, b.column);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < b.column; j++)
            {
                double value = 0;
                for (int k = 0; k < b.row; k++)
                {
                    value += a.getValue(i, k) * b.getValue(k, j);
                }
                multiMatrix.setValue(i, j, value);
            }
        }
        return multiMatrix;
    }
    else
    {
        std::cerr << "The number of columns in the first matrix should be equal to the number of rows in the second.";
        return Matrix();
    }
}

Quadratic matrixMultiplication(const Quadratic &a, const Quadratic &b)
{
    if (a.row == b.row)
    {
        Quadratic resultMatrix(a.row);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.row; j++)
            {
                double value = 0;
                for (int k = 0; k < b.row; k++)
                {
                    value += a.getValue(i, k) * b.getValue(k, j);
                }
                resultMatrix.setValue(i, j, value);
            }
        }
        return resultMatrix;
    }
    else
    {
        std::cerr << "The number of columns in the first matrix should be equal to the number of rows in the second.";
        return Quadratic();
    }
}

Quadratic::Quadratic(unsigned short r) : Matrix(r, r), row(r) {}

Quadratic::~Quadratic() {}

double Quadratic::determinant() const
{
    if (row == 1)
    {
        return getValue(0, 0);
    }

    double det = 0;
    int sign = 1;
    for (int i = 0; i < row; i++)
    {
        det += getValue(i, 1) * cofactor(i, 1);
        sign *= -1;
    }

    return det;
}

double Quadratic::minor(unsigned short r, unsigned short col) const
{
    Quadratic iM(row - 1);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i < r && j < col)
            {
                iM.setValue(i, j, getValue(i, j));
            }
            else if (i > r && j > col)
            {
                iM.setValue(i - 1, j - 1, getValue(i, j));
            }
            else if (i < r && j > col)
            {
                iM.setValue(i, j - 1, getValue(i, j));
            }
            else if (i > r && j < col)
            {
                iM.setValue(i - 1, j, getValue(i, j));
            }
        }
    }

    return iM.determinant();
}

double Quadratic::cofactor(unsigned short r, unsigned short col) const
{
    return minor(r, col) * pow(-1, r + col);
}

Quadratic Quadratic::adjointMatrix() const
{
    Quadratic adjent(row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            adjent.setValue(i, j, cofactor(i, j));
        }
    }

    return adjent.transpose();
}

Quadratic Quadratic::inverseMatrix() const
{
    double det = determinant();
    if (determinant() == 0)
    {
        std::cerr << "The determinant is 0, the matrix is not invertible";
        return *this;
    }

    return adjointMatrix().multiply(1 / det);
}