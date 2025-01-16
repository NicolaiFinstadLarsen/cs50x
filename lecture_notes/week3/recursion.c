#include <cs50.h>
#include <stdio.h>

// Jeg er ikke helt klar på hvordan dette virker.

// Prototype
void draw(int n);

int main(void)
{
    // Hente inn høyde fra user og call function draw med argument denne inputten.
    int height = get_int("Height: \n");
    draw(height);
}

// Vi bruker type void fordi funksjonen ikke skal returnere noe, den skal kun printe.
void draw(int n)
{
    // Basecase hvis n er 0 eller mindre. Så vi ikke itterere n negativ for alltid.
    if (n <= 0)
    {
        return;
    }
    // Recursion med å calle draw funksjonenen inne i seg selv. Dette fordi vi skal printe alle frem til n.
    // Vi caller altså funksjonen med n-1, så n vil reduseres for hver gang vi caller vår funksjon.
    // Derfor må vi også passe på at n ikke kan bli negativ.
    draw(n-1);

    // Og denne delen sier hvor mange # det er per linje.
    // Vi begynner å printe på n=1 og n øker for hver runde med +1
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
