# https://cs50.harvard.edu/x/2024/psets/6/readability/

# const given from task
const = 15.8
const_l = 0.0588
const_s = 0.296


def main():
    # text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere."
    text = input("String: ")

    # Calling funions for counting different values I will neeed.
    char_count = calc_char(text)
    word_count = calc_words(text)
    sentences_count = calc_sentences(text)

    # Calling the funtion for calculation l and s and multiplying with the proper factor.
    after_value_l = calc_l(char_count, word_count) * const_l
    after_value_s = calc_s(word_count, sentences_count) * const_s

    # Calling funtion for calculating the total grad
    total = calc_total(after_value_l, after_value_s, const)

    # Calling funtion to print the correct grade in terminal
    final_grade = grade(total)

    print(final_grade)

    # My debugging print statements
    '''
    print(char_count)
    print(word_count)
    print(sentences_count)
    print(after_value_l)
    print(after_value_s)
    print(total)
    '''

# sum every one of the chars that are alphanumerical and adds 1 each time.
def calc_char(t):
    count = sum(1 for c in t if c.isalpha())
    return count


# Sum the number of times we itterate over a whitespace and adds 1 each time
def calc_words(t):
    count = sum(1 for i in t.split())
    return count


# Increases the count by one for each time we itterate over a "?" or "." or "!"
# These are the paramenters in my task
# This would not work in a real scenario
def calc_sentences(t):
    count = 0
    for c in t:
        if c == "." or c == "?" or c == "!":
            count += 1
    return count


# The avg amount of chars per 100 words
def calc_l(char, word):
    return (char/word) * 100


# The avg amount of sentences per 100 words
def calc_s(word, sentence):
    return (sentence/word) * 100


# Calculatin the total from pre given formula
# Making sure to round for the later print statement
def calc_total(value_l, value_s, const):
    return round(value_l - value_s - const)


# Handeling the different grades and return the correct string to print.
def grade(total_score):
    if total_score < 1:
        return "Before Grade 1"
    if 1 <= total_score <= 16:
        return f"Grade {total_score}"
    if total_score > 16:
        return "Grade 16+"


main()
