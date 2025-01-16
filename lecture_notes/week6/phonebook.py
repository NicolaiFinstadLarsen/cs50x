names = ["David", "Carter", "John"]

name = input("Name: ")

for n in names:
    if n == name:
        print("Found")
        break

# Vi kan faktisk ha en else statement i for loopen vår.
# #Dette sikrer at vi ikke printer not found med en gang første index i listen ikke er navnet vi søker etter.
else:
    print("Not found")


## Vi trenger strengt tatt ikke en for loop i det hele tatt for å lete gjennom en liste.
if name in names:
    print("Found again")
else:
    print("Not found again")

