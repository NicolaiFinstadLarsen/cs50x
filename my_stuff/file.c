#include <stdio.h>
#include <stdlib.h>

/*
--------------------------------------
    Denne koden vil ikke gi noen resultater slik den kjøres nå.
    For å få noe ut av koden må vi kommentere ut deler slik at
    vi ikke sitter med en variabel verdi på EOF
    eller at vi prøver å skrive til samme fil flere ganger ved bruk av samme ptr.
--------------------------------------
*/

int main(void)
{
    // Read for å bare kunne lese
    FILE* ptr1 = fopen("my_file_test.txt", "r");
    if(ptr1 == NULL)
    {
        return 1;
    }

    // Write for å lage ny fil hver gang
    FILE* ptr2 = fopen("my_file_2.txt", "w");
    if(ptr2 == NULL)
    {
        return 1;
    }

    // Append for å ikke legge til i fil
    FILE* ptr3 = fopen("my_file_3.txt", "w");
    if(ptr3 == NULL)
    {
        return 1;
    }

    // Vi lager en variabel ch
    // Vi lager en while loop som er true så lenge ch ikke er EOF
    // EOF er et kodeord for End Of File
    // Vi printer hver char og ender med en newline utenfor loop.
    char ch;
    while((ch = fgetc(ptr1)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");

    // Her kan vi putte inn en char per kjøring.
    // Husk at vi må bruke ' ' når vi jobber med char. " " virker ikke.
    // I denne koden peker ptr2 til en fil med write
    // Vi sletter derfor gammel tekst hver gang vi kjører koden.
    // Den kan også brukes med append
    fputc('a', ptr2);

    // Denne koden kopierer fra filen til ptr1
    // Og legger den inn i filen til prt3
    // char for char
    // Vi kan ikke kjøre denne sammen med den forrige while loopen.
    // Jeg tror det er fordi vi bruker samme ptr og den før verdi EOF.
    // Forrige whileloop er derfor kommentert ut.

    while((ch = fgetc(ptr1)) != EOF)
    {
        fputc(ch, ptr3);
        printf("%c", ch);
    }

    /*
    -----------------------------------
    Under har vi forskjellige måter å lese og å skrive til filer på.
    Denne koden vil ikke gi noen resultater slik den kjøres nå.
    For å få noe ut av koden må vi kommentere ut deler slik at
    vi ikke sitter med en variabel verdi på EOF
    eller at vi prøver å skrive til samme fil flere ganger ved bruk av samme ptr.
    -----------------------------------
    */

    // Vi initialiserer enn arr på størrelse 10
    // Vi leser gjennom filen til ptr1
    // Men kun opp til 10* strl av en int
    int arr[10];
    fread(arr, sizeof(int), 10, ptr1);

    // Vi allokerer minne for arr2 på størrelse av 80 * en dobbel
    // Vi leser så filen til arr2
    // Men kun til lengden av 80 * dobbel
    double* arr2 = malloc(sizeof(double) * 80);
    fread(arr2, sizeof(double), 80, ptr1);

    // Vi initialiserer en char variabel c
    // Vi leser så av 1 stk char i filen til ptr1
    // Denne blir så lagret i ved å gå til adressen til char c
    char c;
    fread(&c, sizeof(char), 1, ptr1);

    /*
    -------------------------------------
    Under finner vi tre forskjelige måter å bruke fwrite og
    forskjellige måter å bruke buffer på
    -------------------------------------
    */

    fwrite(arr, sizeof(int), 10, ptr3);

    // Her skriver vi verdiene til arr2 i filen til ptr3
    // Men bare frem til lengden av 80 * dobbel
    fwrite(arr2, sizeof(double), 80, ptr3);

    fread(&c, sizeof(char), 1, ptr3);


    // Stenger filen, tar en pointer
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    free(arr2);
    return 0;
}
