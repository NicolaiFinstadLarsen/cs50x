#include <stdio.h>
#include <cs50.h>

int main(void)
{

    /*Strings*/

    
    printf("Hello, World\n");

    string name = get_string("What's your name? \n");
    string last_name = get_string("And your last name? \n");

    printf("Your name is: %s\n", name);

    printf("Hello, %s %s\n", name, last_name);


}

