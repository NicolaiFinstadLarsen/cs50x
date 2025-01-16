#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Lage et program som tar inn 26 bokstaver. Og kun 26 bokstaver. Som vi kaller key
// Deretter kartlegge disse mot alfabetet
// Deretter ta input fra user
// Output = input omkodet fra key

// Er ikke dette xlookup egentlig?

int plain_text(string text);

int main(void)
{
    string alphabet = "ABCDEFGHIJKLMENOPQRSTUVWXYZ";
    string key = get_string("Key: ");
    string text = get_string(" ");
    int length = strlen(key);

    int x = plain_text(text);
    printf("%c", x);

    int i;

    for (i = 0; i < length; i++)
    {
        printf("%i,", key[i]);
        //finn på hvilken plass bokstaven på ith plass i string text er i alphabet og print ut ith plass av key
    }
    printf("\n");
}


int plain_text(string text)
{
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++)
    {
        return text[i];
        //finn på hvilken plass bokstaven på ith plass i string text er i alphabet og print ut ith plass av key
    }
    printf("\n");
}
