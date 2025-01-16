# Importering av argv ettersom det ikke kommer standard.
from sys import argv

# Vi kjører ved å skrive python greet_sys.py Nico
# Men argv kjenner bare 2 stk command line argumenter
# Ordet python blir ignorert
if len(argv) == 2:
    print(f"Hello {argv[1]}")
else:
    print("Hello world")
