#include <stdio.h>

int main(void)
{
    //variabel
    int n = 50;

    // Deklarering av pointer, altså deklarere en variabel som vil lagre en adresse ved å bruke &
    // Kan også skrives slik int* p = &n;
    // Det viser at int* er typen, p er variabel navnet.
    int *p = &n;

    // Vi printer ut adressen av n ved å bruke &. Vi må også skrive ut ved å bruke %p for å skrive en adresse.
    printf("%p\n", &n);

    // Vi skriver ut en int ved å bruke %i og int'en er den som ligger i pointer p.
    // Ved å bruke *p uten å spesifisere en type, sier vi bare "gå til dette stedet" og vis hva som er der. 
    printf("%i\n", *p);
}
