#https://youtu.be/EHi0RDZ31VA?t=4365

before = input("Before: ")
print("After: ", end="")

for c in before:
    print(c.upper(), end="")
print() # for en ny linje

# end="" stopper en ny linje per hver itirasjon av c
# kan også brukes slik:

b4 = "dog"
print("After: ", end="")
print(b4.upper())

# Også med en f string og uten temp variabel for endring fra lower to upper.

b4_2 = "fish"
print(f"After: {b4_2.upper()}")
