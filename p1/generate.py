import random
import sys

int32max = 2 ** 31 - 1
int32min = 2 ** 31 * -1

def main():
    if len(sys.argv) != 2:
        print("USAGE: python generate.py <number of numbers>")
        return
    x = int(sys.argv[1])
    for i in range(0, x):
        print(str(random.randint(int32min, int32max)))
main()
