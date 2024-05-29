/**
 * In C++, we have classes that help us obtain type information at compile time.
 * We can use these classes by including the "type_traits" header.
 * This is helpful when we want to write more generic and type-safe code.
 *
 * Commonly used classes:
 * - std::is_integral: Checks if a type is an integral type (e.g., int, char, bool).
 * - std::is_floating_point: Checks if a type is a floating-point type (e.g., float, double).
 * - std::is_arithmetic: Checks if a type is an arithmetic type (either integral or floating-point).
 * - std::is_pointer: Checks if a type is a pointer type.
 * - std::is_array: Checks if a type is an array type.
 * - std::is_reference: Checks if a type is a reference type.
 * - std::is_same: Checks if two types are the same.
 * - std::is_const: Checks if a type is const.
 * - std::is_volatile: Checks if a type is volatile.
 * - std::remove_const: Removes the const qualifier from a type.
 * - std::remove_volatile: Removes the volatile qualifier from a type.
 * - std::remove_reference: Removes the reference qualifier from a type.
 * - std::enable_if: Enables a function or class template specialization only if a certain condition is met.
 *
 * Reference: https://cplusplus.com/reference/type_traits/
 */

#include <iostream>
#include <type_traits>

// the usage is simple, in this example we declare a simple is array function
// tho this example is stupid and redundant, I decide to use it just to show some example

// Function template to check if a type is an array
// Note: this is a function tample, we dont pass any parameters here, because it will decays the type to a pointer.
template <typename T>
bool isArray()
{
    return std::is_array<T>::value;
}

// here another example, I create an overload function, where we can pass parameter by reference (to avoid decays) to find the variable type
/**
 * Drawbacks of this overload:
 * - Requires an actual object (needs an instance) as a parameter to check the type.
 * - Cannot be used with nullptr and temporary objects because it requires a reference to an actual object.
 * - The function might accidentally modify the variable because it is passed by reference.
 * - Having overloads that pass by type and by reference can be confusing.
 */
template <typename T>
bool isArray(T &variable)
{
    return std::is_array<T>::value;
}

/**
 * TODO: Will add some more exammples on the typeTraits, maybe some more complex or weird examples
 */

int main()
{

    int myNumberNotAnArray = 10;
    int myArrayOfNumber[10] = {};
    double myDoubleArray[5] = {};
    char myChar = 'a';
    char myString[] = "Hello";

    // Note: We use std::boolalpha to convert the boolean result (0 or 1) into true or false.

    std::cout << "Is myNumberNotAnArray an array? : " << std::boolalpha << isArray(myNumberNotAnArray) << std::endl;
    std::cout << "Is myArrayOfNumber an array? : " << std::boolalpha << isArray(myArrayOfNumber) << std::endl;

    std::cout << "Is myDoubleArray an array? : " << std::boolalpha << isArray<decltype(myDoubleArray)>() << std::endl;
    std::cout << "Is myChar an array? : " << std::boolalpha << isArray<decltype(myChar)>() << std::endl;
    std::cout << "Is myString an array? : " << std::boolalpha << isArray<decltype(myString)>() << std::endl;
}