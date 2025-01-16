# En liste med 3 stk dictionaries
people = [
    {"name": "Nico", "number": "92421609"},
    {"name": "Tonny", "number": "90076651"},
    {"name": "Kim", "number": "92231460"},
]

# Prompt for input name to search for
name = input("Name: ")

# Vi leter gjennom alle i listen people
# Vi leter etter om input er likt som key i dict
# Hvis likt printer vi value av dict
# Vi finner dette ved å bruke tempvariabel["Key eller value"]
for p in people:
    if p["name"] == name:
        print(f"Found {p['number']}")
        break
else:
    print("Not found")
