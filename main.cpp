#include <iostream>
#include "matris.cpp"

int main()
{
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);

    matrix1.setValue(0, 0, 1);
    matrix1.setValue(0, 1, 2);
    matrix1.setValue(0, 2, 3);
    matrix1.setValue(1, 0, 4);
    matrix1.setValue(1, 1, 5);
    matrix1.setValue(1, 2, 6);
    matrix1.setValue(2, 0, 7);
    matrix1.setValue(2, 1, 8);
    matrix1.setValue(2, 2, 9);

    matrix2.setValue(0, 0, 9);
    matrix2.setValue(0, 1, 8);
    matrix2.setValue(0, 2, 7);
    matrix2.setValue(1, 0, 6);
    matrix2.setValue(1, 1, 5);
    matrix2.setValue(1, 2, 4);
    matrix2.setValue(2, 0, 3);
    matrix2.setValue(2, 1, 2);
    matrix2.setValue(2, 2, 1);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    std::cout << "Matrix Addition:" << std::endl;
    Matrix sum = matrixAddition(matrix1, matrix2);
    sum.display();

    std::cout << "Matrix Multiplication:" << std::endl;
    Matrix product = matrixMultiplication(matrix1, matrix2);
    product.display();

    std::cout << "Transpose of Matrix 1:" << std::endl;
    Matrix transposed = matrix1.transpose();
    transposed.display();

    Quadratic quadraticMatrix(3);

    quadraticMatrix.setValue(0, 0, 2);
    quadraticMatrix.setValue(0, 1, 2);
    quadraticMatrix.setValue(0, 2, 3);
    quadraticMatrix.setValue(1, 0, 4);
    quadraticMatrix.setValue(1, 1, 5);
    quadraticMatrix.setValue(1, 2, 6);
    quadraticMatrix.setValue(2, 0, 7);
    quadraticMatrix.setValue(2, 1, 8);
    quadraticMatrix.setValue(2, 2, 9);

    std::cout << "Quadratic Matrix:" << std::endl;
    quadraticMatrix.display();

    std::cout << "Determinant of Quadratic Matrix: " << quadraticMatrix.determinant() << std::endl;

    std::cout << "Adjoint of Quadratic Matrix:" << std::endl;
    Quadratic adjoint = quadraticMatrix.adjointMatrix();
    adjoint.display();

    std::cout << "Inverse of Quadratic Matrix" << std::endl;
    Quadratic inverse = quadraticMatrix.inverseMatrix();
    inverse.display();

    return 0;
}
