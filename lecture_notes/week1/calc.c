#include <stdio.h>
#include <cs50.h>

int add(int num1, int num2);

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");

    /*
    int z = add(x, y);
    printf("The answer is %i \n", z);
    */

    printf("The answer is %i \n", add(x,y));
}

int add(int num1, int num2)
{
    return num1 / num2;
}
