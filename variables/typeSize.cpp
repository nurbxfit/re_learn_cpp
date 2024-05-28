/**
 * In C++, each data type has a specific size that determines the range of values it can store in memory.
 * If we store a number in a variable that exceeds the type's maximum limit, it will overflow and wrap around to the minimum limit value.
 * If we store a number in a variable that is smaller than the type's minimum limit, it will underflow and wrap around to the maximum limit value.
 *
 * Note:
 * - We can determine the size of a variable using the 'sizeof' operator, e.g., sizeof(int).
 * - We can find the minimum and maximum limits of a numeric type using the static methods 'std::numeric_limits<T>::min()' and 'std::numeric_limits<T>::max()'.
 */

#include <iostream>
#include <limits>
#include <typeinfo>

template <typename T>
void printOverUnderFlow()
{
    T overflow = std::numeric_limits<T>::max();
    T underflow = std::numeric_limits<T>::min();

    // Demonstrate overflow and underflow
    overflow++;
    underflow--;

    std::cout << "Overflow Value after incrementing max: " << overflow << std::endl;
    std::cout << "Underflow Value after decrementing min: " << underflow << std::endl;
}

template <typename T>
void printMinMax()
{
    std::cout << std::endl;
    std::cout << "Min Value of " << typeid(T).name() << " : " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "Max Value of " << typeid(T).name() << " : " << std::numeric_limits<T>::max() << std::endl;

    printOverUnderFlow<T>();
}

int main()
{
    printMinMax<short>();
    printMinMax<int>();
    printMinMax<float>();
    printMinMax<double>();
    printMinMax<long>();
    printMinMax<long long>();
    printMinMax<unsigned int>();

    return 0;
}
