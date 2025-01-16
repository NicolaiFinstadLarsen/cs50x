#include <stdio.h>
#include <cs50.h>

void meow(int n);
int main(void)
{

    {
        meow(2);
    }
}



void meow(int n)
{
    for(int i = 0; i < 3; i++)
    {
        printf("meow \n");
    }
}
