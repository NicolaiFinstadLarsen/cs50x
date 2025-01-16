#include <stdio.h>

int main(void)
{
    // Vi bruker ikke "get_int" lenger som er en del av cs50.h
    int n;
    // Vi må printe noe for å vise hva vi vil ha av user.
    printf("n: ");
    // vi scanner etter en int via %i og legger det i adressen til n
    scanf("%i", &n);
    // Så kan vi printe ut på vanlig måte.
    printf("n: %i\n", n);

}
