#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //do while n<1. Meaning: prompt user for a positive num
    do
    {
        n = get_int("Size ");
    }
    while (n < 1);

    //build an n by n block of #
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
