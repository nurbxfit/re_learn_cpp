/**
 * Templating allows us to declare functions and classes that can operate with generic types.
 * This enables us to write code that can work with any data type without needing to be rewritten
 * for each specific type.
 *
 * Usage:
 *
 * template <typename identifier, typename identifier> function_declaration;
 *  or
 * template <class identifier> function_declaration;
 *
 * 'typename' and 'class' are interchangeable in the context of templates.
 * 'identifier' is the placeholder for the type that will be specified when the template is instantiated.
 */

#include <iostream>
#include <stdexcept>

/*
 * In the example below, we create a template, that accept two numbers and add it together.
 * Noted that here the function accept any type either integer, double or float.
 * without templating, we need to overload our function and copied the definition for different data types
 */

template <typename T>
T add(T firstNumber, T secondNumber)
{
    return firstNumber + secondNumber;
}

/**
 * The above example shows the general usage of a template; it only accepts the same data type for both parameters.
 * In the example below, we make our template accept two different data types as parameters.
 * This is achieved by overloading the previous function template by providing it with two template parameters.
 *
 * This still reduces the need to overload the function for all combinations of data types.
 *
 * In this example the return type will be auto, which will be deduce by the compiler
 * thru implicit/explicit conversion.
 *
 * For example if we add 'int' and 'double' like this
 * auto result = add(10,2.5);
 * the return type is 'double' due to the implicit conversion by the compiler.
 *
 * We can also explicitly specify the return type like this
 * int result = add(10,2.5); // this can cause some issue when the compiler will convert the double result into int, which can result in a loss of percision.
 *
 *
 * Note: it's best to let the compiler deduce the return type using the 'auto'
 * or maybe using decltype(auto)
 *
 * Example below is the use of decltype
 * it is used to deduce the type of a variable
 * decltype can also be used to declare variables with types derived from expressions:
 */
template <typename T, typename U>
auto add(T firstNumber, U secondNumber) -> decltype(firstNumber + secondNumber)
{
    // this is just to showcase the use of decltype,
    decltype(firstNumber + secondNumber) result = firstNumber + secondNumber;

    // we can use auto if we want
    // auto result = firstNumber + secondNumber;

    return result;
}

/**
 * We can also use templating when defining a class,
 * Here we declared a class that accepts a generic type as the class constructor parameters
 * This single class can be reused with a Int or double type.
 */

template <typename T>
class MaxMinimum
{
public:
    MaxMinimum(T first, T second) : first(first), second(second) {} // example of member initialization.
    T getMax() const { return first > second ? first : second; }
    T getMin() const { return first < second ? first : second; }

private:
    T first, second;
};

int main()
{
    std::cout << add(5, 3.2) << std::endl;                                      // Example of using the template with int and double
    std::cout << add(std::string("Hello "), std::string("World")) << std::endl; // Example with std::string

    auto resultImplicit = add(10, 2.5);
    int resultExplicit = add(10, 2.5);

    std::cout << "ResultImplicit:" << resultImplicit << std::endl;
    std::cout << "ResultExplicit:" << resultExplicit << std::endl;

    MaxMinimum<int> mySet(1, 2);
    std::cout << "Max:" << mySet.getMax() << ", Min:" << mySet.getMin() << std::endl;

    MaxMinimum<double> mySetDouble(13.4, 12.2);
    std::cout << "Max:" << mySetDouble.getMax() << ", Min:" << mySetDouble.getMin() << std::endl;

    return 0;
}