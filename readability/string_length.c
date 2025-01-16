#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");

    // Vi kan initializ'e to variabler i forloopen ved å bruke en komme. Her finner vi lengdene \n
    //  Ved å gjøre det på denne måten kan vi itterat'e over variablene bare en gang men med færre \n
    //  linjer enn å lage en egen variabel for lengde.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}
