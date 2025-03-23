#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <numbers>
int main()
{
    int a = 1;
    unsigned int b = 2;
    bool c = true; // false;
    double d = 1.2030; // 1.2e-12 oppure 1.2f e ottengo un float;
    std::string str = "hello";
    char e = 'a';

    std::cout << "hello" << std::endl;

    std::cout << sizeof(int) << std::endl;
    std::cout << -pow(2 ,31) << " " << pow(2, 31) - 1 << std::endl;
    std::cout << std::numeric_limits<int>::min() << " " <<
    std::numeric_limits<int>::max()<< std::endl;
    std::cout << std::setprecision(16) << std::scientific;
    std::cout << std::numbers::pi << std::endl;
    int a1 = a + 36;
    std::cout << "a1 = " << a1 << std::endl;



    return 0;
}
