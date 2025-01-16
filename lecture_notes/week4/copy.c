#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Jeg bruker char * her for å vise tydelig at string egentlig bare er char * altså en pointer.
    char *s = get_string("i: ");
    char *t = s;

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    // Dette printer ut uppercase på begge s og t fordi vi mapper char t til adressen til s.
    // Se copy2.c for bruk av malloc og løsning.
    printf("%s\n", s);
    printf("%s\n", t);
}
