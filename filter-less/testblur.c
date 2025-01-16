#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

#include "helpers.c"


int main(void)
{
    // Create a copy of image
    /*
    int image[3][9] = {{10,20,30,40,50,60,70,80,90},
                        {110,130,140,120,140,150,130,150,160},
                        {200,210,220,220,230,240,240,250,255}};

    */

   RGBTRIPLE image[3][3] = {
    {{10,20,30},{40,50,60},{70,80,90}},
    {{110,130,140},{120,140,150},{130,150,160}},
    {{200,210,220},{220,230,240},{240,250,255}}
   };

    int height = sizeof(image)/sizeof(image[0]) - 1;
    int width = sizeof(image[0])/sizeof(image[0][0]) - 1;

   RGBTRIPLE(*image2)[width] = calloc(height, width * sizeof(RGBTRIPLE));



    for (int i = 0; i <= height; i++)
    {
        image2[i] = &image[i];
    }

    blur(height, width, image2);
/*
    int copy[3][9];

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

*/
    /*
    a b c
    d x f
    g h i
    */
/*
    for (int h = 0; h <= height; h++)
    {
        for (int w = 0; w <= width; w++)
        {
            int sum = 0;
            int count = 0;

            // Behandler "a"
            if(h != 0 && w != 0)
            {
                sum = sum + copy[h-1][w-1];
                count++;
            }
            // Behandler "b"
            if(h != 0)
            {
                sum = sum + copy[h-1][w];
                count++;
            }
            //Behandler "c"
            if(h != 0 && w < width)
            {
                sum = sum + copy[h-1][w+1];
                count++;
            }
            // Behandler "d"
            if(w != 0)
            {
                sum = sum + copy[h][w-1];
                count++;
            }
            //Behandler "X"
            sum = sum + copy[h][w];
            count++;

            //Behandler "f"
            if(w < width)
            {
                sum = sum + copy[h][w+1];
                count++;
            }
            //Behandler "g"
            if(w != 0 && h < height)
            {
                sum = sum + copy[h+1][w-1];
                count++;
            }
            //Behandler "h"
            if(h < height)
            {
                sum = sum + copy[h+1][w];
                count++;
            }
            //Behandler "i"
            if(w < width && h < height)
            {
                sum = sum + copy[h+1][w+1];
                count++;
            }

            int avg = round(sum/count);


            */
            /*
            if(j - 1 < 0 || i - 1 < 0 || j + 1 >= width || i + 1 >= height)
                {
                    ;
                }

            double temp_blue = ((copy[i-1][j-1] + copy[i][j-1] + copy[i+1][j-1] +
            copy[i-1][j] + copy[i][j] + copy[i+1][j] +
            copy[i-1][j+1] + copy[i][j+1] + copy[i+1][j+1]) / 9.0);
            */

            /*
            //int rgb_avg_blue = round(temp_blue);


            //image[i][j] = rgb_avg_blue;
            image[h][w] = avg;
            printf("%i ", image[h][w]);
        }
        printf("\n");
    }
*/
}
