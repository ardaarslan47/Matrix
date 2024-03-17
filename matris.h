#include <iostream>

class Matrix
{
private:
    unsigned short row;
    unsigned short column;
    double **content;

public:
    Matrix(unsigned short col, unsigned short r);
    Matrix(){};
    virtual ~Matrix();

    void setValue(unsigned short col, unsigned short r, double value);
    double getValue(unsigned short col, unsigned short r) const;

    void display() const;

    Matrix transpose() const;
    Matrix multiply(double by) const;

    friend Matrix matrixAddition(const Matrix &a, const Matrix &b);
    friend Matrix matrixMultiplication(const Matrix &a, const Matrix &b);
};

class Quadratic : public Matrix
{
private:
    unsigned short row;

public:
    Quadratic(unsigned short r);
    Quadratic(){};

    ~Quadratic();

    double minor(unsigned short r, unsigned short col) const;
    double cofactor(unsigned short r, unsigned short col) const;
    double determinant() const;

    Quadratic transpose() const;
    Quadratic multiply(double by) const;

    Quadratic adjointMatrix() const;
    Quadratic inverseMatrix() const;

    friend Quadratic matrixAddition(const Quadratic &a, const Quadratic &b);
    friend Quadratic matrixMultiplication(const Quadratic &a, const Quadratic &b);
};