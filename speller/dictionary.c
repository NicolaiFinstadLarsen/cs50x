// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//functions
unsigned int hash_val;
unsigned int count_words;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_val = hash(word);
    node *place = table[hash_val];

    while (place != 0)
    {
        if(strcasecmp(word, place->word) == 0)
        {
            return true;
        }
        place = place->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long tot = 0;
    int i;

    for(i = 0; i < strlen(word); i++)
    {
        tot += tolower(word[i]);
    }
    return tot % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *my_file = fopen(dictionary, "r");
    if (my_file == NULL)
    {
        printf("%s could not open\n", dictionary);
        return false;
    }
    char word[LENGTH +1];
    while(fscanf(my_file, "%s", word) != EOF)
    {
        node *ptr = malloc(sizeof(node));
        if(ptr == NULL)
        {
            return false;
        }

        strcpy(ptr->word, word);
        hash_val = hash(word);
        ptr->next = table[hash_val];
        table[hash_val] = ptr;
        count_words++;
    }
    fclose(my_file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(count_words > 0)
    {
        return count_words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int i;
    for(i = 0; i < N; i++)
    {
        node *place = table[i];
        while (place)
        {
            node *temp = place;
            place = place-> next;
            free(temp);
        }

    }
    return true;
}
