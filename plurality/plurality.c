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

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //TODO
    // Itterates over i up to candidate count.
    // Then compares candidate name to name of vote
    // of candidate name and vote name match. Add one to candidate vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            //printf("%i", candidates[i].votes);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //printf("%i\n", candidate_count);
    //printf("%i\n", candidates[0].votes);


    int tot_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > tot_count)
        {
            tot_count = candidates[i].votes;
        }
    }

    // As long as j is less then candidate count.
    // Check the candidates vote count.
    // If the vote count is greater then the last biggest one
    // Use that count instead
    // In the end we print the candidates with a votecount equal the highest vote count
    // This means we also print more than one since sevral candidates can have \n
    // the same amount of votes.
    int j = 0;
    while (j < candidate_count)
    {
        if (candidates[j].votes == tot_count)
        {
            //printf("Winner is\n");
            printf("%s\n", candidates[j].name);
        }
        j++;
    }
}
