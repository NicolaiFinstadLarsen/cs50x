// From youtube BroCode video https://www.youtube.com/watch?v=Vh4krbTnTAA (C 2D arrays)

#include <cs50.h>
#include <stdio.h>


int main(void)
{

/* ------------------------

//Dette er hvordan man setter opp en 2D array
//Husk at vi må legge inn argumenter for lenge av row og kollonne
//Her legger vi inn 2 rader og 3 kollonner.

    int numbers[2][3] = {
                        {1,2,3},
                        {4,5,6}
                        };

    printf("%i\n", numbers[1][0]);
*/


/* ------------------------
//Dette er hvordan man legger til verdier i en 2D array

    int numbers[2][3];

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;

//For å printe ut verdiene i en matrise/2D array må vi bruke en nested loop
//Første loop ittererer over radene
//Andre loop ittererer over kollonnene

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%i ", numbers[i][j]);
            //printf("Ny kollonne \n");
        }
        printf("\n");
        //printf("Ny rad \n");

    }

*/

//Hvordan vi setter opp nested loopen med størrelse av rows og colums.

    int numbers[3][3];

//Vi lager to verdier som vi kan bruke i nested loopene
//Disse finner lengden av arrary ved å bruke sizeof
//Vi deler sizeof numbers på sizeof 1 row for å finne hvor mange rows det er.
//Vi deler sizeof 1 row på size of 1 colum for å finne hvor mange colums det er.

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int colums = sizeof(numbers[0])/sizeof(numbers[0][0]);

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;
    numbers[2][0] = 7;
    numbers[2][1] = 8;
    numbers[2][2] = 9;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            printf("%i ", numbers[i][j]);
        }
        printf("\n");
    }

return 0;
}

