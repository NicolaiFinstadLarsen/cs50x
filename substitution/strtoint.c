#include <cs50.h>
#include <stdio.h>
#include <string.h>

int key_print(string text, int length, int* list);

int main(void)
{
    // String for vår basecode
    string alph = "abc";

    //string for vår cipher key
    string key = get_string("Input: ");

    //String til vår plaintext
    //string plaintext = get_string("Text: "\n);

    int length_key = strlen(key);
    int length_alph = strlen(alph);

    printf("%i ", key_print(key, length_key, int* list));

    int i;
    for(i = 0; i < length_alph; i++)
    {
        //Her kan vi printe ut ACSII nummeret til bokstavene i alph
        printf("%i ", alph[i]);
    }
    printf("\n");
    /*
    int j;
    for(j=0; j < length_key; j++)
    {
        //Her kan vi printe ut ACSII nummeret til bokstavene i key
        printf("%i ", key[j]);
    }
    printf("\n");
    */
}


int key_print(string text, int length, int* list)
{
    int j;

    for(j=0; j < length; j++)
    {
        //Her kan vi printe ut ACSII nummeret til bokstavene i key
        list[j];
    }
    return list;
}
