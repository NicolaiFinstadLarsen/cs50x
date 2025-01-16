#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string x = get_string("What is your name? ");
    {
        // Yes, the hello should be all lower
        printf("hello, %s\n", x);
    }
}
