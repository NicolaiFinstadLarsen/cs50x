#include <cs50.h>
#include <stdio.h>

// Prototype
float avg_score(int length, int array[]);

// Constant global variable
const int N = 3;

int main(void)
{
    // Collect scores to average out.
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: \n");
    }

    // Print statement calls the function and we execute from line 24
    printf("Snitt: %f \n", avg_score(N, scores));
}

// Funtion to average the score by adding the scores to a sum variable by the ith index in array
float avg_score(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
