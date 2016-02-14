import sys

if len(sys.argv) != 2: sys.exit()

with open(sys.argv[1], 'r') as f:
    for line in f:
        print(line)
