#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

#include "helpers.c"

int main(void)
{

    RGBTRIPLE image[3];


    image.rgbtRed = {
    {10,20,30},{110,130,140},{200,210,220}}
    image.rgbtGreen = {
    {40,50,60},{120,140,150},{220,230,240}}
    image.rgbtBlue = {
    {70,80,90},{130,150,160},{240,250,255}}


    //int height = sizeof(image)/sizeof(image[0]) - 1;
    //int width = sizeof(image[0])/sizeof(image[0][0]) - 1;
    blur(3, 3, image);
}
