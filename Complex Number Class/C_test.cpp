#include "C.cpp"
#include <iostream>


int main()
{
    C complex_num1(1.0, -3.0);
    C complex_num2(1.0, -3.0);

    std::cout << complex_num1 * complex_num2 << std::endl;

    return 0;
}