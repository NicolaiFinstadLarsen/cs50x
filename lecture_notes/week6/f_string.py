from cs50 import get_string as gs

name = gs("What's your name? ")
year = int(input("What year were you born? "))
age = 2024 - year

print(f"Hi {name}! Since you were born in {year}, you're {age} years old if you already celebrated your birthday this year. If you did not, you are {age-1} year young.")

#get_string og get_int er fra cs50 lib og er egentlig bare der for å gjøre overgangen fra C til python lettere. Tilsvarer input i python og er ikke nødvendig.
# Jeg typecaster input med int() for å kunne gjøre matematiske operasjoner på variabelen. Dette fordi input alltid er string.
