
#funksjon for å kunne spørre om en int av bruker
# Funksjonen tar en verdi, denne kommer fra main funksjonen når vi skal sette verdi til x og y og caller get_int.
def get_int(prompt):
    # For å kjøre spørringen så frem til vi får en int
    while True:
        #Vi prøver å ser om det er en int
        try:
            return int(input(prompt))
        # Hvis det er en ValueError, pass og gå på nytt.
        except ValueError:
            #print("NaN, use int.")
            pass

def main():
    x = get_int("x: ")
    y = get_int("y: ")
    print(x + y)


main()
