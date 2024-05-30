
#include <iostream>
#include <cstdlib>
#include <ctime>

int genRand(int limit = 10)
{
    static bool seeded = false;
    if (!seeded)
    {
        int seedElapsedSeconds = std::time(nullptr);
        std::srand(seedElapsedSeconds);
        seeded = true;
    }
    return std::rand() % limit;
}

int main()
{

    std::cout << "Random: " << genRand() << std::endl;
    std::cout << "Random: " << genRand(100) << std::endl;
    std::cout << "Random: " << genRand(50) << std::endl;

    return 0;
}