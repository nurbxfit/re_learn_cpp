/**
 * Variadic templates are a feature of C++ that allow us to write functions or classes
 * that accept a variable number of arguments.
 *
 * The variadic template syntax uses an ellipsis `...` (pack expansion) to indicate
 * that a function or class template can accept any number of parameters.
 * Internally, variadic templates often use recursion to process each argument.
 *
 * Variadic templates provide type safety because the types of all arguments are known
 * at compile-time, making them flexible and powerful tools in template metaprogramming.
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

/**
 * Here is an example on how we can use the variadic tempaltes concept in a class
 */

template <typename... Args>
class CustomArray
{
public:
    CustomArray(Args... args) : size(sizeof...(Args)), elements{args...}
    {
    }

    void print() const
    {
        std::cout << "[ ";

        /**
         * Note on the apply function:
         * std::apply() is a c++  17 function defined in the <tuple> header. It invokes a given function with arguments take from a tuple.
         * In this example it takes a lambda function:
         *
         * [this](auto &&..args){
         *  printElements(std::foward<decltype(args)>(args)...);
         * }
         * and the elements as second parameters.
         *
         * About the lambda function:
         * the line: std::forward<decltype(args)>(args), ensure that the argument are forwarded with original value category (lvalue or rvalue)
         * the iine: [this](auto &&..args) is the argument where it caprute `this` by refenrece to access the elements variable value.
         * the auto &&...args, means for forwarding reference
         */
        std::apply([this](auto &&...args)
                   { printElements(std::forward<decltype(args)>(args)...); }, elements);
    }

private:
    std::tuple<Args...> elements;
    size_t size;

    template <typename... Ts>
    void printElements(Ts...) const
    {
    } // Empty tuple case (base case)

    // here we define our Base templat
    template <typename T>
    void printElements(T value) const
    {
        std::cout << value << " ]" << std::endl;
    }

    // Here we declare the overload recursion;
    template <typename T, typename... Rest>
    void printElements(T first, Rest... rest) const
    {
        std::cout << first << ", ";
        printElements(rest...);
    }
};

int main()
{
    // exmaple using of the print function
    print(1, "Hello World", 3.142, "Somebody", "once");

    // example usgin the class print method
    CustomArray<int, double, std::string> array(1, 3.142, "Hello World");

    // alternatively we can deduce the type using the compiler
    CustomArray secondArray("Never Gonna Give", "You", "Up", 3.142, "Hello World", 12, 0.4);

    array.print();
    secondArray.print();

    return 0;
}