#include <stdio.h>
#include <cs50.h>

#include "helpers.h"


int main(void)
{
int array1[9] = {1,2,3,4,5,6,7,8,9};
int array2[9] = {9,8,7,6,5,4,3,2,1};

int size1 = sizeof(array1)/sizeof(array1[0]);
int size2 = sizeof(array2)/sizeof(array2[0]);

for(int i = 0; i < size1; i++)
{
    for(int j = 0; j < size2; j++)
    {
        if(j -1 && i-1 < 0)
        {
            continue;
        }
        int x = (array1[i] + array2[j+1]) / 2;
        //printf("J in array 2 is: %i ", array2[j]);
        printf("This is the avg. of 'Array1' %i + 'Array2' %i also known as X = %i\n", array1[i], array2[j+1], x);
    }
    printf("\n");
}
return 0;
}




