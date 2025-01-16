#include <stdio.h>

// Prototype. Vi må bruke pointer her også hvis funksjon forventer pointer
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is : %i, y is: %i\n", x, y);
    // Kaller swap her, husk å bruke adresse tegn forran variabel hvis funksjon forventer pointer.
    swap(&x, &y);
    printf("x is : %i, y is: %i\n", x, y);
}

// Funksjon forventer pointer
void swap(int *a, int *b)
{
    // Vi bruker deklarering for å gå til adressen av variablene vi legger inn
    // Dette er også hvorfor vi må bruke adressetegn når vi kaller funksjonen i main.
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
