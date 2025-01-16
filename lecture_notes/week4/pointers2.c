#include <stdio.h>

int main(void)
{
    // En string er bare en char * pointer som er ferdig kodet i cs50.h.
    // Det vi egentlig gjør er å bruke en char * pointer når vi printer ut.
    char *s = "HI!";

    // Vi kan printe ut string ved å bruke samme syntax
    printf("%s\n", s);
    // Vi kan printe ut første char ved å bruke *s for å gå til adresse og vise hva som er der (første char i array'en)
    printf("%c\n", *s);
    // Vi kan også bruke "pointer arithmetic ved å pluss på et tall å få ut hva som er på adressen + tallet.
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    // Setter jeg * på innsiden av parantesen går jeg til hva som er i adressen på s og gir neste char som kommer på ASCII tabellen?
    printf("%c\n", (*s + 2));
    printf("%c\n", (*s + 19));
}
