#include "helpers.h"
#include <math.h>
#include <stdio.h>

//Prototype
double calculate_average(int i, int j, RGBTRIPLE image[i][j], char color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // Finner en avarage av alle tre fargene og legger denne verdien til alle tre fargene
            // Dette skaper en slags skala mellom hvitt og svart.
            double temp = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            int rgb_avg = round(temp);

            image[i][j].rgbtBlue = rgb_avg;
            image[i][j].rgbtRed = rgb_avg;
            image[i][j].rgbtGreen = rgb_avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // Bruker formelen for de forskjellige endringene av farge og legger dette til
            // temp variabler
            double temp_red =
                image[i][j].rgbtRed * 0.393
                + image[i][j].rgbtGreen * 0.769
                + image[i][j].rgbtBlue * 0.189;

            // Passer også på at det ikke er verdier over 255 (8bit farge).
            // Hvis over setter til 255
            if(temp_red > 255)
            {
                temp_red = 255;
            }

            // Samme for grønn
            double temp_green =
                image[i][j].rgbtRed * 0.349
                + image[i][j].rgbtGreen * 0.686
                + image[i][j].rgbtBlue * 0.168;

            if(temp_green > 255)
            {
                temp_green = 255;
            }

            // og blå
            double temp_blue =
                image[i][j].rgbtRed * 0.272
                + image[i][j].rgbtGreen * 0.534
                + image[i][j].rgbtBlue * 0.131;

            if(temp_blue > 255)
            {
                temp_blue = 255;
            }

            // Bruker så temp variabler for å legge inn i 2d arrayen.
            // Jeg trenger ikke temp variabler, men hvis jeg skal endre noe er det sikkert fint å ha.
            //Fant en feil etter jeg var ferdig med blur. La til round() for å få riktig verdi.
            image[i][j].rgbtBlue = round(temp_blue);
            image[i][j].rgbtRed = round(temp_red);
            image[i][j].rgbtGreen = round(temp_green);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Lager variabel for å dele bilde i 2 over kollonner
    int half = width/2;

    for(int h = 0; h < height; h++)
    {
        //printf("Hei h %i\n", h);
        // Bruker half for å ikke itterere over hele bildet
        for(int w = 0; w < half; w++)
        {

            /*
            From Rubberduck AI:
            You needed to add -1 because array indices in C are zero-
            based. This means the last element of an array with width
            elements is at index width-1. Without the -1, you were
            accessing an out-of-bounds index, which caused incorrect
            behavior.
            */
            //printf("Hade w %i\n", w);
            // Bruker temp variabler for å spare på piksler fra høyre side av bilde
            // Bruker width-w som nedtelling her.
            double temp_right_blue = image[h][width-w-1].rgbtBlue;
            double temp_right_green = image[h][width-w-1].rgbtGreen;
            double temp_right_red = image[h][width-w-1].rgbtRed;

            // Legger venstre side av bilde over på høyre side
            image[h][width-w-1].rgbtBlue = image[h][w].rgbtBlue;
            image[h][width-w-1].rgbtGreen = image[h][w].rgbtGreen;
            image[h][width-w-1].rgbtRed = image[h][w].rgbtRed;

            // Legger temp variablene fra høyre side inn på venstre side.
            image[h][w].rgbtBlue = temp_right_blue;
            image[h][w].rgbtGreen = temp_right_green;
            image[h][w].rgbtRed = temp_right_red;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for (int h = 0; h <= height; h++)
    {
        for (int w = 0; w <= width; w++)
        {
            int sum_red = 0;
            int sum_blue = 0;
            int sum_green = 0;
            float count = 0;
            //printf("Hade %i-%i\n", h,w);

            /*
            Vi går gjennom if statementes for alle "nabo" pixler av pixelen vi er på i for loopen.
            Vi sjekker om verdiene kan brukes eller ikke og summerer opp og øker count per if statement som blir brukt
            Det er mye frem og tilbake på range av array her. Men det virker nå.
            */
            // Behandler "a"
            if(h != 0 && w != 0)
            {
                sum_red = sum_red + copy[h-1][w-1].rgbtRed;
                sum_green = sum_green + copy[h-1][w-1].rgbtGreen;
                sum_blue = sum_blue + copy[h-1][w-1].rgbtBlue;
                count++;
            }
            // Behandler "b"
            if(h != 0)
            {
                sum_red = sum_red + copy[h-1][w].rgbtRed;
                sum_green = sum_green + copy[h-1][w].rgbtGreen;
                sum_blue = sum_blue + copy[h-1][w].rgbtBlue;

                count++;
            }
            //Behandler "c"
            if(h != 0 && w + 1 < width)
            {
                sum_red = sum_red + copy[h-1][w+1].rgbtRed;
                sum_green = sum_green + copy[h-1][w+1].rgbtGreen;
                sum_blue = sum_blue + copy[h-1][w+1].rgbtBlue;
                count++;
            }
            // Behandler "d"
            if(w != 0)
            {
                sum_red = sum_red + copy[h][w-1].rgbtRed;
                sum_green = sum_green + copy[h][w-1].rgbtGreen;
                sum_blue = sum_blue + copy[h][w-1].rgbtBlue;
                count++;
            }
            //Behandler "X"
                sum_red = sum_red + copy[h][w].rgbtRed;
                sum_green = sum_green + copy[h][w].rgbtGreen;
                sum_blue = sum_blue + copy[h][w].rgbtBlue;
                count++;

            //Behandler "f"
            if(w + 1 < width)
            {
                sum_red = sum_red + copy[h][w+1].rgbtRed;
                sum_green = sum_green + copy[h][w+1].rgbtGreen;
                sum_blue = sum_blue + copy[h][w+1].rgbtBlue;
                count++;
            }
            //Behandler "g"
            //Vi må legge til +1 på h for å sjekke at array kan finne verdi i h+1, dette var grunnen til seg dump.
            //Gjaldt flere av de nederste pixlene og topp høyere mener jeg å huske.
            if(w != 0 && h +1 < height)
            {
                sum_red = sum_red + copy[h+1][w-1].rgbtRed;
                sum_green = sum_green + copy[h+1][w-1].rgbtGreen;
                sum_blue = sum_blue + copy[h+1][w-1].rgbtBlue;
                count++;
            }
            //Behandler "h"
            if(h + 1 < height)
            {
                sum_red = sum_red + copy[h+1][w].rgbtRed;
                sum_green = sum_green + copy[h+1][w].rgbtGreen;
                sum_blue = sum_blue + copy[h+1][w].rgbtBlue;
                count++;
            }
            //Behandler "i"
            if(w + 1 < width && h + 1 < height)
            {
                sum_red = sum_red + copy[h+1][w+1].rgbtRed;
                sum_green = sum_green + copy[h+1][w+1].rgbtGreen;
                sum_blue = sum_blue + copy[h+1][w+1].rgbtBlue;
                count++;
            }
            // finner et gjennomsnitt og runder av verdien
            int avg_red = round(sum_red/count);
            int avg_green = round(sum_green/count);
            int avg_blue = round(sum_blue/count);

            //Legger verdien tilbake i originalbildet.
            image[h][w].rgbtBlue = avg_blue;
            image[h][w].rgbtRed = avg_red;
            image[h][w].rgbtGreen = avg_green;
            }
        }
}
