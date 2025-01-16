#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *ptr = "Hello";
    int n;
    n = 5;
    //printf("%40s\n", ptr);
    printf("%*s%s\n", n, "", ptr);
}
