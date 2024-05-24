#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * In C++ we can use templating such as : template< typename T> or template <class T> ;
 * the 'T' is a placeholder for any data type.
 * This allow us to write a single function definition that can operate on any data type.
 */

template <typename T>
T addTwoNumbers(T first, T second)
{
    return first + second;
}

template <typename T>
T multiplyTwoNumbers(T first, T second)
{
    return first * second;
}

template <typename T>
T divideTwoNumbers(T first, T second)
{
    if (second == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }
    return first / second;
}

// notes to self:
// example of templating with two different types
// doing this alone will only accepts type other than string as its parameters
// if we pass in string it will throw an error due to std::to_string only accept numeric types
// to overcome this we can overload our function or maybe specialize it.

template <typename T, typename U>
std::string concat(T first, U second)
{
    return std::to_string(first) + std::to_string(second);
}

// example of using tempalte specialization to concat string and other value
template <typename U>
std::string concat(const std::string &first, U second)
{
    std::ostringstream oss;
    oss << first << second;
    return oss.str();
}

// say if user excidentally insert a string in the second argument, we can overload it like this ?
template <typename U>
std::string concat(U first, const std::string &second)
{
    std::ostringstream oss;
    oss << first << second;
    return oss.str();
}

int main()
{
    int i1 = 10, i2 = 15;
    double d1 = 10.2, d2 = 2.0;
    float f1 = 24.0, f2 = 1.5;

    std::cout << "Int addition: " << addTwoNumbers(i1, i2) << std::endl;
    std::cout << "Double multiplication: " << multiplyTwoNumbers(d1, d2) << std::endl;
    try
    {
        std::cout << "Float division: " << divideTwoNumbers(f1, f2) << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Output the results of concatenation
    std::string s = "Hello";
    int n = 42;
    std::cout << "Concatenated string: " << concat(s, n) << std::endl;
    std::cout << "Concatenated string: " << concat(n, s) << std::endl;
    return 0;
}
