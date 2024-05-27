/**
 * C++ is a statically typed language,
 * meaning that the type of a variable must be declared
 * and cannot be changed throughout the program.
 *
 * This is unlike dynamically typed languages such as Python, JavaScript, and Ruby.
 */

#include <iostream>

/**
 * Here are examples of basic data types and their sizes in memory:
 * - short: 2 bytes; -32,768 to 32,767
 * - int: 4 bytes; -2,147,483,648 to 2,147,483,647
 * - long: usually 4 or 8 bytes, depending on the system (typically the same as long long on most modern systems)
 * - long long: 8 bytes; -(2^63) to (2^63 - 1)
 * - float: 4 bytes; single-precision floating-point
 * - double: 8 bytes; double-precision floating-point
 * - long double: typically 8, 12, or 16 bytes, depending on the system
 * - bool: 1 byte; true or false
 * - char: 1 byte; typically -128 to 127 or 0 to 255
 * - auto: the type is inferred from the initializer
 */

/**
 * Notes:
 * - When using decimal values, appending type suffixes is important for clarity.
 *   The compiler will treat them as double by default even if the variable is declared as float.
 * - When using a float value, append 'F' or 'f' at the end.
 * - When using a long value, append 'L' or 'l' at the end.
 * - When declaring a large number and then assigning it to a smaller variable, narrowing conversion might occur, causing data loss.
 */

int main()
{
    double price = 1.20;
    float rate = 0.65F;        // Note that we append the letter 'F' at the end so that the compiler does not cast it to double.
    long digitalSize = 10000L; // Note that we append the letter 'L'.
    char grade = 'D';
    bool isValid = false;
    auto myValue = 10;
    auto isFalse = true;

    // We can also declare our variables using brace initialization.
    int number{10};  // This initializes our variable with 10.
    int zero{};      // This initializes our variable with 0.
    int randomValue; // This declares the variable without initializing it; it will contain a garbage value.

    int bigNumber = 1'000'000;
    short smallNumber = bigNumber; // This will cause a narrowing conversion; the value will be truncated, possibly causing data loss.

    std::cout << "number: " << number << std::endl;
    std::cout << "zero: " << zero << std::endl;
    std::cout << "randomValue: " << randomValue << std::endl; // Warning: may print a garbage value.
    std::cout << "bigNumber: " << bigNumber << std::endl;
    std::cout << "smallNumber: " << smallNumber << std::endl; // Demonstrates the effect of narrowing conversion.

    return 0;
}
