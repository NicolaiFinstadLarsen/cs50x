#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // Do this to get an input
    do
    {
        n = get_int("Size ");
        if (n > 8 || n < 0)
        {
            n = get_int("Size ");
        }
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        int counter = n - (i + 1);
        /*
        We only print if counter is more than 0 since we dont want the code to run once more \n
        when counter == 0 and print a space on last line.
        */
        if (counter > 0)
        {
            /*
            We print out the string, with variable len based on variable counter that \n
            counts n-(1+1). (counter sjekk) printf("%i", counter);
            */
            printf("%*s", counter, "");
        }
        for (int a = 0; a <= i; a++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
