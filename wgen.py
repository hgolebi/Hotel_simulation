from locale import format_string
import random

file = open("workers.txt", "w")
file.write("id profession cash\n")
for i in range(0, 101):

    prof = random.randint(0, 3)
    if i < 4:
        prof = i
    cash = random.randint(100, 1000)
    file.write(f"{i} {prof} {cash}\n")

file.close()