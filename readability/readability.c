#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


// The "Coleman-Liau index".
// Formula for "Coleman-Liau index" index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text

int antall_ord();
int antall_bokstaver();
int antall_setninger();

int main(void)
{
    // String from user
    string input_text = get_string("Text: ");

    // Putting the function returns in to variables for easier work.
    int tot_ord = antall_ord(input_text);
    int tot_bokstaver = antall_bokstaver(input_text);
    int tot_setninger = antall_setninger(input_text);

    // Math for the formula to work
    float factor = (float) 100 / tot_ord;
    float L = factor * tot_bokstaver;
    float S = factor * tot_setninger;

    // More math for the formula
    float calc_L = (float) 0.0588 * L;
    float calc_S = (float) -0.296 * S;
    float X = (float) -15.8;

    // Formula and rounding as per the task output we want.
    float index = calc_L + calc_S + X;
    int round_index = round((float) index);

    // If statement for correct output from index score.
    if (round_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round_index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", round_index);
    }
}

// Function for number of words in string.
int antall_ord(string text)
{

    int count = 0;

    // Variabel for lengden av string
    int length = strlen(text);

    // Itterere over lengden av string
    for (int i = 0; i < length; i++)
    {
        // Hvis char i ith plass i string == mellomrom count+=1
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // Retur ordcount men +1 fordi vi teller mellomrom ikke ord.
    return count + 1;
}

// Function for number of letters in string
int antall_bokstaver(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        // If statement uses the ASCII mapping of letters. We could have used isalpha i guess\n
        // But i learned about that later in this script.
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count++;
        }
    }
    return count;
}

// Function for number of sentences.
int antall_setninger(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i <= length; i++)
    {
        // Nested if statement for firstly the three sentence endring punctuations.
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            // But then we look for edgecases when next char is not alpha of digit.
            // Meaning apostrophe etc will not count.
            if (i + 1 < length && (!isalpha(text[i + 1]) || !isdigit(text[i + 1])))
            {
                count++;
            }
            // Then we find out if the string acctually ends. Since this is its own edge case.
            else if (i == length - 1 && (!isalpha(text[i + 1]) || !isdigit(text[i + 1])))
            {
                count++;
            }
        }
    }
    return count;
}
