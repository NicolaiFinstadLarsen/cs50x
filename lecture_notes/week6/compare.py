a = "Yo"
b = "Yo"
if a == b:
    print("Same")
# Man kan sammenligne strings


# method eksempel. OOP = object oriented programming gir mulighet for å ha funksjon på variabler og i variabel biblioteket og ikke bare i sitt eget bibliotek.
# F.eks. .lower() hvor .lower() er en metod i string biblioteket

s = input("Do you agree? ").lower()

if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")
else:
    print("Not a valid input (y, yes, n, no)")


