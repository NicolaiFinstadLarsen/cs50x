n = int(input("n: "))

print(" " * (n), end="")
print("#", end="")

for i in range(n):

    print(" " * (n-i), end="")
    print("#" * (i+i))
