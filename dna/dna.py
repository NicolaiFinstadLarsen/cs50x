import csv
import sys

LENGTH_COMMANDLINE_ARG = 3


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != LENGTH_COMMANDLINE_ARG:
        print(f"Use like this: python dna.py database.csv squances.txt")
        sys.exit()

    database = make_database(sys.argv[1])
    sequences = make_sequence(sys.argv[2])
    str_matching = finding_str(database, sequences)
    database_check(database, str_matching)


def make_database(f):
    try:
        # TODO: Read database file into a variable
        # Opening the filename from commandline as db_file
        with open(f, "r") as db_file:
            # List comprehension and also using the csv lib with DictReader
            # DictReader uses first row as key and rest as values.
            db = [row for row in csv.DictReader(db_file)]
            return db
    except FileNotFoundError:
        print(f"File {f} not found")


def make_sequence(f):
    # TODO: Read DNA sequence file into a variable
    # Opening file and makeing sure they all can be int's
    try:
        with open(f, encoding="utf-8") as seq_file:
            return seq_file.read()
    except Exception as e:
        print(f"Error type: {e}")


def finding_str(db, seq):
    # TODO: Find longest match of each STR in DNA sequence
    # Mapping the name in index 0 to the longest match for that name
    counter = {}
    # Itterating thru the database names (index 0)
    for key in db[0].keys():
        # Skipping same name
        if key == "name":
            continue
        # Checking length of name with longest_match function
        counter[key] = longest_match(seq, key)
    return counter


def database_check(db, counter):
    # TODO: Check database for matching profiles
    # Itterating thru each row in db
    for row in db:
        match = True
        # Checking for same name
        for key in row.keys():
            if key == "name":
                continue
            # Checking to see if we have a match and if that match is the same length as counter
            if key in counter and int(row[key]) != counter[key]:
                match = False
                break
        if match:
            print(row["name"])
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
