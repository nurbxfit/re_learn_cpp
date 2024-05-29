#include <iostream>

void swapNumbers(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int integerNumber01 = 100, integerNumber02 = 50;

    std::cout << "i.First:" << integerNumber01 << std::endl;
    std::cout << "1.Second:" << integerNumber02 << std::endl;
    std::cout << "Swaping...:" << std::endl;
    swapNumbers(integerNumber01, integerNumber02);
    std::cout << "f.First:" << integerNumber01 << std::endl;
    std::cout << "f.Second:" << integerNumber02 << std::endl;

    return 0;
}
