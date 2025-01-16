#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Vi kan faktisk legge inn størrelsen på en int.
    // Det kan være greit hvis ikke alle os har samme størrelse på en int.
    int *x = malloc(3 * sizeof(int));

    // Vi har nå lagt til verdier i posisjoner som er utenfor arraystørrelsen vi malloc'et
    // Vi malloc'et 3 * stizeof(int) men vi har lagt til verdier i index 3
    // Det er altså på plass 4 ( vi starter fra 0)
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x);

    // For å sjekke om det er noen memoryleak's
    // Kjør valgrind .memory i commandline
}
