/**
 * In C++ we can declare a number variable using decimal, hexadecimal, and binary representations.
 * We can also declare a number as signed or unsigned.
 * A signed number means it can be negative or positive.
 * An unsigned number means it will always be positive.
 *
 * For example:
 * If we declare an unsigned integer variable and accidentally assign it a negative value,
 * the actual value will be converted into a large positive value due to underflow.
 */

#include <iostream>

int main()
{
    int myDecimalValue = 10;        // Decimal representation
    int myBinaryNumber = 0b0001010; // Binary representation (C++14 and later)
    int myHexNumber = 0xA;          // Hexadecimal representation

    std::cout << "Decimal (10): " << myDecimalValue << std::endl;
    std::cout << "Binary (0b0001010): " << myBinaryNumber << std::endl;
    std::cout << "Hexadecimal (0xA): " << myHexNumber << std::endl;

    // Be careful when using the unsigned keyword.
    unsigned int badNegativeNumber = -1; // This will become 4294967295 instead of -1 due to overflow.
    std::cout << "Unsigned int assigned -1: " << badNegativeNumber << std::endl;

    return 0;
}
