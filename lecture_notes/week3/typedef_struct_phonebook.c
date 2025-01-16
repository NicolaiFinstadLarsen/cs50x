#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Typedef struct lager en datatype
// her bruker vi det for å lage en "dict{}"
// Vi avslutter typedef struct med hva vi skal kalle datastructuren vår
typedef struct
{
    string names;
    string number;
} person;

int main(void)
{
    // Her legger vi inn dataen vi vil ha i vår datastructure.
    // Vi bruker også et tall her for å si hvor mange oppføringen vi skal ha.
    // Dette er ikke best praksis seff.
    person people[3];
    people[0].names = "Nicolai";
    people[0].number = "92421609";

    people[1].names = "Tonny";
    people[1].number = "90076651";

    people[2].names = "Kim";
    people[2].number = "92174767";

    // User input prompt
    string s = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        // Her bruker vi nå strcmp for å sammenligne ith oppføring i vår datastruct "people" og verdien "names"
        // Vi sammenligner det med s og ser etter retur av verdi 0.
        // Dette er case sensitive!
        if (strcmp(people[i].names, s) == 0)
        {
            // Vi printer her da ut "found" og oppføringen på ith plass med verdien til "number"
            // Vi returnerer også verdien 0 for å avlutte programmet.
            printf("Found\nTlf: %s\n", people[i].number);
            return 0;
        }
    }
    // Har vi gått igjennom hele og ikke funnet noe. Returnerer vi not found og kode 404
    printf("Not found\n");
    return 404;
}
