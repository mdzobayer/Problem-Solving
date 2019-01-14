#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <string>

using namespace std;

int main()
{
    const auto start = std::chrono::system_clock::now();
    if (complex_calculation())
    {
        std::cout <<
            std::chrono::duration<double>{
                std::chrono::system_clock::now() - start
            }.count() << "s\n";
        return EXIT_FAILURE;
    }else {
        std::cout <<
            std::chrono::duration<double>{
            std::chrono::system_clock::now() - start}.count() << "s\n";
        return EXIT_SUCCESS;
    }
}
