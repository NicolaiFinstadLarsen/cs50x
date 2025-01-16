#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
int main(void)
{
    string s = get_string("Before ");
    printf("After ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
*/


// Det finnes et lib som heter ctype som inneholder toupper \n
// Dette pass gjennom det som ikke trenger endres \n
// Derfor ikke nødvendig med all koden over.

int main(void)
{
    string s = get_string("Before ");
    printf("After ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
