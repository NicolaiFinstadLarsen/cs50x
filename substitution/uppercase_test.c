#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* key_upper(string a);

int main (void)
{

    string b = get_string("Input: \n");
    string upper_key = key_upper(b);

    printf("%s\n", upper_key);
    free(upper_key);

}

char* key_upper(string a)
{

    int len = strlen(a);
    char* new_text = malloc((strlen(a) + 1) * sizeof(char));

    for(int i = 0; i<len; i++)
    {
        new_text[i] = toupper(a[i]);

    }
    new_text[len] = '\0';
    return new_text;
}
