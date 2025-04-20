#include "square-mat.hpp"
using namespace Matrix;
int main(){
    int count=0;
    SquareMat mat1 = SquareMat(2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);
    std::cout << "Test 1: Constructor and set/get\n";
    std::cout << "mat1:\n" << mat1 << std::endl;

    // Test 2: Addition operator
    SquareMat mat2(2);
    mat2.set(0, 0, 5);
    mat2.set(0, 1, 6);
    mat2.set(1, 0, 7);
    mat2.set(1, 1, 8);
    std::cout << "mat2:\n" << mat2 << std::endl;
    SquareMat mat3 = mat1 + mat2;
    std::cout << "Test 2: Addition operator\n";
    std::cout << "mat1 + mat2:\n" << mat3 << std::endl;

    // Test 3: Subtraction operator
    SquareMat mat4 = mat2 - mat1;
    std::cout << "Test 3: Subtraction operator\n";
    std::cout << "mat2 - mat1:\n" << mat4 << std::endl;

    // Test 4: Scalar multiplication operator
    double scalar = 2;
    SquareMat mat5 = mat1 * scalar;
    std::cout << "Test 4: Scalar multiplication operator\n";
    std::cout << "mat1 * 2:\n" << mat5 << std::endl;

    // Test 5: Equality operator
    SquareMat mat6(2);
    mat6.set(0, 0, 1);
    mat6.set(0, 1, 2);
    mat6.set(1, 0, 3);
    mat6.set(1, 1, 4);
    std::cout << "Test 5: Equality operator\n";
    std::cout << "mat1 == mat6: " << (mat1 == mat6) << std::endl;

    // Test 6: Inequality operator
    std::cout << "Test 6: Inequality operator\n";
    std::cout << "mat1 != mat2: " << (mat1 != mat2) << std::endl;

    // Test 7: Transpose
    SquareMat mat7 = ~mat1;
    std::cout << "Test 7: Transpose\n";
    std::cout << "Transpose of mat1:\n" << mat7 << std::endl;

    // Test 8: Determinant
    double det = !mat1;
    std::cout << "Test 8: Determinant\n";
    std::cout << "Determinant of mat1: " << det << std::endl;

    // Test 9: Multiplication operator
    SquareMat mat8 = mat1 * mat2;
    std::cout << "Test 9: Multiplication operator\n";
    std::cout << "mat1 * mat2:\n" << mat8 << std::endl;

    // Test 10: Output operator
    std::cout << "Test 10: Output operator\n";
    std::cout << "Matrix mat1:\n" << mat1 << std::endl;

    std::cout << "All tests completed!" << std::endl;
    return 0;
}