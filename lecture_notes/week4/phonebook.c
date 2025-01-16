#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Åpne en fil.
    // Velger også om vi vil read"r", write"w"
    // eller append"a"
    // For en tlfbok gir det mening med "a"
    // så vii ikke overwrite.
    // fopen åpner en fil og returnerer en pointer
    // Derfor må vi bruke en pointer
    FILE *file_ptr = fopen("phonebook.csv", "a");

    // Hvergang vi returnerer en pointer burde denne koden være med.
    // Det for å sikre at vi ikke har noen memory problemer.
    if(file_ptr == NULL)
    {
        return 1;
    }

    // Vi bruker char * for å ikke bruke treninghjul
    char *name = get_string("Name ");
    char *number = get_string("Number ");

    // Her printer vi 2 stk strings til filen vi har åpnet
    // Og vi legger inn name og number
    // Vi legger inn en \n for å skille mellom innføringer
    fprintf(file_ptr, "%s,%s\n", name, number);

    // Tilslutt lukker vi filen.
    fclose(file_ptr);
}
