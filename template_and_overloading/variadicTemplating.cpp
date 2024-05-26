/**
 * Variadic templates, are a feature of C++ that allow use to write function or classes
 * that accept variable or varibales .
 *
 * The variadic template function use an ellipsis `...` to allow a function to accept any numbers of parameters / templates
 * Internally it  use recursion to process each argument.
 *
 * variadic template provide type safety because athe type of all arguments are known at compile-time.
 * it is also very flexible.
 */

#include <iostream>

// Base function: Example of a template function that accepts a single argument to print
template <typename T>
void print(T arg)
{
    std::cout << arg << std::endl
              << "<> Reach End </>" << std::endl;
}

// we can overload above code to accept any numbers of arguments to print
template <typename T, typename... Args> // by using elipsis, we assume it accept n number of arguments by capruting the rest of argument type into the Args.
void print(T first, Args... args)
{
    std::cout << first << ", ";
    print(args...); // then we recursively call the function passing the rest of the arguments, reducting the arguments.
    /**
     * note: at the end of the function call where it accept single argument. it will call the  base function
     * which will result of printting the "<>Reach End</>" into the console
     * */
}

int main()
{
    print(1, "Hello World", 3.142, "Somebody", "once");
    return 0;
}