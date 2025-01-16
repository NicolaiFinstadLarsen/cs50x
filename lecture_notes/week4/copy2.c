#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Jeg bruker char * her for å vise tydelig at string egentlig bare er char * altså en pointer.
    char *s = get_string("i: ");
    // Vi allokerer minne for en string vi skal kopiere fra s.
    // Vi bruker lengden på s + 1 for å ha plass til \0 som avslutter string'en.
    char *t = malloc(strlen(s) + 1);
    // Dette betyr at t har for lite minne.
    if(t == NULL)
    {
        return 1;
    }

    // Videre må vi bruke en loop for å itterer over alle char i s å legge de til i array t.
    // Legg merke til at vi bruker en komma , og n = strlen(s) i for funksjonen.
    // Vi bruker også i<=n fordi vi må ta med siste char som er \0 i string s.
    // Vi kunne også lagd en egen variabel slik:
    // int n = strlen((s)+1)
    for(int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Vi trenger ikke å bruke en for loop for å mappe hver char fra t til s.
    // string.h har strcpy
    // Vi legger inn destinasjon først og kilde som nr 2.
    strcpy(t, s);

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    // Dette printer ut uppercase på begge s og t fordi vi mapper char t til adressen til s.
    // Se copy2.c for bruk av malloc og løsning.
    printf("%s\n", s);
    printf("%s\n", t);

    // Vi trenger også å frigjøre minnet vi har brukt i malloc.
    // Siden vi brukte malloc for å lage t må vi derfor frigjøre t
    free(t);
    // return 0; er bare standard kode ok.
    return 0;
}
