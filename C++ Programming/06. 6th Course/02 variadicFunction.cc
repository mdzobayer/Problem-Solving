/**
#include <stdio.h>
#include <stdarg.h>

void PrintStrings(int n, ...)
{
    va_list vl;
    va_start(vl,n);
    for (int i = 0; i < n; i++)
    {
        const char *val = va_arg(vl,const char *);
        printf(" [%s]",val);
    }
    va_end(vl);
    printf("\n");
}**/
#include <iostream>
void print()
{
}

template <typename First, typename ... T>
void print(First&& f, T&& ... t)
{
    std::cout << " [" << f << ']';
    print(t...);
}
template <typename ... T>
void printValues(T&& ... t)
{
    print(std::forward<T>(t)...);
    std::cout << std::endl;
}

int main()
{
    //PrintStrings(4, "a", "b", "c", 5);
    printValues("a", "b", "c", 5, 6.15);

    return (0);
}
