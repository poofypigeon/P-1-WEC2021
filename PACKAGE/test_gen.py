import string
import random

def main():
    fname = input("Input the name of the file you'd like to generate: ")
    num = int(input("Input the number of words you want to generate: "))

    f = open(fname, "w")

    for i in range(num):
        f.write(f"{rand_str()}\n")

    f.close()

def rand_str():
    letters = string.ascii_letters
    result_str = ''.join(random.choice(letters) for i in range(5))

    return result_str

main()