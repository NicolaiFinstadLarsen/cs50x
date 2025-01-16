#include <stdio.h>

int main(void)
{
    // Vi har bare allokert 4 bytes i array'en.
    // For å finne ut hvor mye vi ternger er det en lang regle med malloc regler
    // Vi lærte ikke dette.
    char s[4];
    printf("s: ");
    scanf("%s", s);

    printf("s: %s\n", s);
}
