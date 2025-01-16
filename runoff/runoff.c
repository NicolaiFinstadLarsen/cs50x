#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // itterere over antalle kandidater og sammenligne string med input
    // hvis string og input er like.
    // oppdatere preferance matrix hvor rad er voter og kolonne er rank
    // Verdien vi legger inn er da j, som er index for kandidat i arrayen.


    for (int j = 0; j < candidate_count; j++)
        if (strcmp(name, candidates[j].name) == 0)
        {
            preferences[voter][rank] = j;
            //printf("%i\n", candidates.name[j]);
            //printf("%d\n", preferences[voter][j]);
            return true;
        }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //TODO
    // Finne voter og voter rank 0
    // Sjekke om voter rank 0 kandidat er elim
    // Hvis ikke elim finne rank 0 kandidat vote++
    // Hvis elim finne voter rank 1 kandidat
    //Hvis ikke elim finne rank 1 kandidat vote ++
    // Osv.


    // Vi ittererer over antall votere
    for(int i = 0; i < voter_count; i++)
    {
        // Og over antall candidter
        for(int j = 0; j < candidate_count; j++)
        {
            // Disse verdiene kan brukes gjennom kandidatene som ligger allerede i preferances matrix'en
            // For å se om de er blitt elimininert

            // Er de eliminert kjører vi en ny runde med ny j
            if(candidates[preferences[i][j]].eliminated == true)
            {
                continue;
            }

            // Er de ikke eliminert legger vi ++ på vote verdien til kandidaten for voter i kandidat j.
            if(candidates[preferences[i][j]].eliminated == false)
            {
                // Vi må også ut av j loopen for å komme oss til neste voter etter at vote på kandidat er ++ på denne voter.
                candidates[preferences[i][j]].votes++;
                //printf("%i\n", candidates[j].votes);
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // Finne antall voters
    // Finne kandidat med >50% av stemmene
    // Printe kandidat som vant og return true
    // Hvis ingen vant return false

    // Første finner vi antallet stemmer som skal til for å ha majoritet.
    // Dette gjøres med float point for å slipp avrundingsfeil.
    int winner_num = voter_count / 2.0;

    // Vi ittererer over candidates

    for(int j = 0; j < candidate_count; j++)
    {
        // Ser om candidate j har flere stemmer enn vinnertallet vi fant
        if(candidates[j].votes > winner_num)
        {
            //Har kandidateten nok stemmer printer vi ut navnet. Med newline for check50.
            printf("%s\n", candidates[j].name);
            // Vi returnerer også true fordi det ønsker main koden.
            return true;
        }
    }
    // Har ingen kandidater nok stemmer for majoritet returnerer funksjonen false.
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // Finne hvilken kandidat som har færres votes og som ikke er elim.
    // Itterere over kandidater og finne antall stemmer
    // Hvis neste kandidat har færre stemmer ta vare på denne kandidaten istedenfor
    // Fortsette til man er ferdig med lengden på kandidater array

    // Lage en variabel som har nummer lik max stemmer
    int min_votes = MAX_VOTERS;

    //Itterere over lengde av antall kandidater
    for(int i = 0; i < candidate_count; i++)
    {
        // Hvis kandidaten har færre stemmer og ikke er eliminert bruk dette antall stemmer som ny min_votes
        if(candidates[i].votes < min_votes && candidates[i].eliminated == false)
        {
            min_votes = candidates[i].votes;
        }
    }
    // Når alle er sjekket returner det minste antallet.
    return min_votes;
    //printf("min votes er: %d ", min_votes);
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    //Finne ut om det faktisk kan være like mange stemmer på alle kandidater
    // Itterere over alle kandidater som ikke er eliminert og se om de har min antall stemmer
    // Returnere true hvis det er sant
    // Ellers returnere false

    // ------Jeg er ikke helt fornøyd med denne løsningen, men den virker.-----

    // Lage variabel for å telle hvor mange kandidater som har riktig antall stemmer og ikke er elimintert
    int counter = 0;
    // Lage variabel for alle kandidater som er eliminert
    int eliminated = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        // Hvis kandidaten har riktig antall stemmer og ikke er eliminert øk counter med 1
        if(candidates[i].votes == min && candidates[i].eliminated == false)
        {
            counter++;
        }
        // Hvis kandidaten er elimintert øk eliminated variabel med 1
        if(candidates[i].eliminated == true)
        {
            eliminated++;
        }
        // Hvis antall kandidater som har riktig antall stemmer og ikke er eliminert
        // == alle kandidater minus de som er eliminert.
        // Return true..
        if(counter == candidate_count - eliminated)
        {
            return true;
        }
    }
    // Ellers return false
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        // Hvis kandidaten har riktig antall stemmer og ikke er eliminert eliminer kandidaten
        if(candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
