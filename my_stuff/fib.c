#include <cs50.h>
#include <stdio.h>

int fib(int n);


int main(void)
{
    printf("%i\n", fib(10));
}

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }


    for(int i = 2; i < n; i++)
    {
        printf("%i\n" , fib(i-1)+fib(i-2));
    }
    return 0;
}
