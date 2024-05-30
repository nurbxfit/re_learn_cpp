#include <iostream>
#include <cmath>

template <typename T>
double calculateAreaOfACirlce(T radius)
{
    const double PI = 3.142;
    return PI * std::pow(radius, 2);
}

int main()
{
    double ceiledResult = std::ceil(1.2);
    double flooredResult = std::floor(1.2);
    double powedResut = std::pow(2, 3);
    int radius = 2;

    std::cout << "ceil(1.2): " << ceiledResult << std::endl;
    std::cout << "floor(1.2): " << flooredResult << std::endl;
    std::cout << "pow(2, 3): " << powedResut << std::endl;
    std::cout << "Area Of Circle Radius " << radius << " is : " << calculateAreaOfACirlce(radius) << std::endl;

    return 0;
}