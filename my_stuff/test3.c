#include<stdio.h>

int main()
{
    int num;

    printf("Enter a number\n");
    scanf("%d",&num);
    int i;

    int my_list[] = {};
    while(num > 0) //do till num greater than  0
    {
        int mod = num % 10;  //split last digit from number
        my_list[i-1] = mod;

        num = num / 10;    //divide num by 10. num /= 10 also a valid one

    printf("%*d \n", my_list);
    }

    return 0;
}
