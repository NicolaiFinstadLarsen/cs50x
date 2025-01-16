#include <cs50.h>
#include <stdio.h>
#include <string.h>

string alphabet = "ABCDEFGHIJKLMENOPQRSTUVWXYZ";

int main(void)
{
    string key = get_string("Key: ");
    //string text = get_string(" ");
    int length = strlen(key);

    int i;

    for (i = 0; i<length; i++)
    {
        printf("%c", alphabet[i]);
    }
    printf("\n");
}
