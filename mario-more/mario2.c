#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, j, i;

    n = get_int("Height: ");

    for (i = 1; i <= n; i++)
    {
        for(j = 1; j <= 2*n-1; j++)
        {
            if(j >= n-(i-1) && j <= n+(i-1))
            {
                printf("#");
            }
            else if(j == n)
            {
                printf(" ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
