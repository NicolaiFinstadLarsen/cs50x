x = int(input("X: (22)"))
y = int(input("Y: (7)"))
z = x/y

# Vi får tilbake en float selv om vi typecaster int i python
print(z)

# Med f string kan vi legge til .50f for å legge til 50 tall etter . og fortelle at det skal være en f for float.
print(f"{z:.50f}")

