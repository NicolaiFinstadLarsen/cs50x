#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x[] = {get_long("Number ")};


    // Vi har initilzed i til 0 her for å kunne printe i før for loopen.
    int i = 0;

    // To find the len of list
    int length = sizeof(x) / sizeof(x[0]);

    // Her printer i = 0
    printf("%i \n", i);

    for(i = 0; i < length; i++)
        printf("%i", x[i]);
    printf("\n");

    // Hvorfor printer vi i = 1 her?
    printf("%i \n", i);


}
