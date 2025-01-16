#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int count = 3;
    while (count > 0)
    {
        printf("meow in a while loop\n");
        count--;
    }

    for(int i=0; i<3;i++)
    {
        printf("meow in a for loop \n");
    }
}
