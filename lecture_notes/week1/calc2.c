#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*
    float x = get_int("x: ");
    float y = get_int("y: ");


    printf("%f \n", x/y);
    */

   //typecasting er her gjort ved at vi endrer variablene a og b til float når vi spør om int av bruker
    int a = get_int("a: ");
    int b = get_int("b: ");

    printf("%f \n", (float) a / (float) b);

}
