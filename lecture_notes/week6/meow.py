# Vi lager main func for å kunne sette hoveddelen av koden over andre hjelpefunksjoner.
# Uten denne hadde det vært umulig å sette selve koden over funksjonen vi ønsker å calle.
def main():
        meow(5)


# Vi har en funksjon.
# Den tar ett paramenter
# Vi bruker det parameteret for å print n antall ganger.
def meow(n):
    for i in range(n):
        print("Meow")


# Konvensjon er å calle main nederst.
main()
