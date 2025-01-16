#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 50;
    for(int x = 0; x < 5; x++)
    {
        char buffer[100];
        sprintf(buffer, "this is cs%i\n", i);
        printf("%s", buffer);
        i = i + 1;
    }

}


