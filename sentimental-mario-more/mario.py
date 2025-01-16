# Tok denne fra forelesningen
# Den sjekker om input faktisk er et tall.
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            # print("NaN, use int.")
            pass


def build():
    # Får en input
    n = get_int("Height: ")

    # Sjekker om input er innenfor parametere for oppgave
    # Er den ikke det spør vi på nytt
    if n < 1 or n > 8:
        print("Not av valid number")
        n = get_int("Height: ")

    # Lager verdens styggeste print.
    # Kunne sikkert delt den opp og brukt ,end=""
    for i in range(1, n+1):
        print(" " * (n-i) + "#" * (i) + "  " + "#" * (i))


build()
