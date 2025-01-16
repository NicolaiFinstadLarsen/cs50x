#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* unique_key_check(string un_key);

int main(void)
{
    string text = get_string("Input: ");
    string new_text = unique_key_check(text);
    printf("%s\n", new_text);
}

char* unique_key_check(string un_key)
{
    int len = strlen(un_key);

    int k = 0;
    while(k < len)
    {
        if(!isalpha(un_key[k]))
        {
            printf("Errormessage: not alpha\n");
            k++;
            return 0;
        }
        k++;
    }
    if(len != 26)
    {
        printf("Errormessage: not 26 digit\n");
        return 0;
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(un_key[j] == un_key[i])
                {
                    printf("Errormessage: values not unique\n");
                    //printf("%i\n", A[j]);
                    //printf("%i\n", A[i]);
                    return 0;
                }
            }
        }
    }
    printf("Return A\n");
    return (un_key);
}


