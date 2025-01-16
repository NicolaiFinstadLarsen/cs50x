import sys
# Husk sys.argv når vi importerer hele sys.
if len(sys.argv) != 2:
    print("Need no more or less than 1 command line argument!")
    sys.exit(1)
    
print(f"Hello {sys.argv[1]}")
sys.exit(0)
