#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

int main(void)
{
    candidate_count = get_int("count: ");
    for(int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = get_string("name: ");
        candidates[i].votes = 0;
    }

    int size =sizeof(candidates)/sizeof(candidates[0]);
    printf("%i\n", size);
}
