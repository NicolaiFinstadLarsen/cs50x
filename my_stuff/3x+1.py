try:
    x = int(input("Pick a number, any number: "))
except ValueError:
    print("Usage: Only whole numbers")
    exit(1)

def calc(num):
    if num == 1:
        print(f"We always end at {num}")
        return

    elif num % 2 == 0:
        new_num = num // 2
        print(f"Even: {num}/2 = {new_num}")
        calc(new_num)
    elif num % 2 != 0:
        new_num = num * 3 + 1
        print(f"Odd: 3*{num}+1 = {new_num}")
        calc(new_num)
calc(x)

