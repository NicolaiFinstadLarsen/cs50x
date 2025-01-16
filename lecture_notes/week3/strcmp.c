#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // En array av strings
    string strings[]={"hello", "who", "are", "dog", "cat", "tree"};
    // User input for en string
    string s = get_string("Input ");

    // Standard for loop, med magic num for enkelhet
    for(int i = 0; i < 6; i++)
    {
        // strcmp som sammenligner strings array ith plass og s
        // Hvis denne returnerer 0 printer vi funnet og avslutter
        if(strcmp(strings[i],s)==0)
        {
            printf("Found\n");
            return 0;
        }
    }
    // Går vi gjennom for loop har vi ikke funnet og kan printe not found.
    printf("Not found\n");
    return 404;
}
