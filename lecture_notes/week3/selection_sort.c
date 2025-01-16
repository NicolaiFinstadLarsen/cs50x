#include <cs50.h>
#include <stdio.h>

int arr[] =  {50,25,15,48,25,2,56,123,63};

int main(void)
{
    int x = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++)
    {
        if(arr[i]<x)
        {
            x = arr[i];
        }
    }
    printf("%i\n", x);
}


//Denne virker!
