#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEADER_SIZE 512
typedef uint8_t byte;

int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        //Sjekker for akkurat ett commandline argument
        // ./recovery == argc 1. filnavn == argc 2.
        printf("Use: ./recover FILE\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if(infile == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 2;
    }

    bool picture_located = false;
    int picture_counter = 0;
    byte buffer[HEADER_SIZE];
    char picture_name [100];
    FILE *outfile = NULL;


    //Bruke fseek()?
    // Kjøre denne så lenge vi ikke er kommet til slutten av filen
    while(fread(buffer, 1, HEADER_SIZE, infile) == HEADER_SIZE)
    {
        // Sjekke om vi har funnet en jpg.
        // Hvis vi finner en. Åpne ny fil med nytt navn og stenge forrige
        // Hvis vi ikke har funnet en
        //(Buffer[3] & 0xf0) == 0xe0) betyr inrange
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(picture_located)
            {
                fclose(outfile);
            }
            else
            {
                picture_located = true;
            }
        // Formatering for å få tre tall i string for å navngi bildene fra counter
        sprintf(picture_name, "%03d.jpg", picture_counter);

        //Åpne en fil får neste bilde
        outfile = fopen(picture_name, "w");
        if(outfile == NULL)
        {
            printf("Can not open %s\n", picture_name);
            fclose(outfile);
            return 3;
        }
        // Øke counter som blir brukt for å navngi bildene
        picture_counter++;
        }
    // Hvis bool sier vi har funnet bilde, skriv til fil.
    if(picture_located)
    {
        fwrite(buffer, HEADER_SIZE, 1, outfile);
    }
    // Stenge while loop før vi stenger filene for siste gang.
    }

    // Lukke inn filen
    fclose(infile);
    // Lukke ut filen
    fclose(outfile);
    return 0;
}
