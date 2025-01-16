#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int velger = 5;
    int rank = 0;

    int height = get_int("height? ");

    //int pref[velger][rank];

    for (int i = 0; i < velger; i++)
    {
        for (int k = 0; k < rank; k++)
       {
            //sette inn kandidate på k'th plass
        }
        printf("\n");

        if (rank < height)
        {
            rank++;
        }

    }
}


