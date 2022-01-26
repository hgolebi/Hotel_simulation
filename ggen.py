from locale import format_string
import random

gfile = open("guests.txt", "w")
gfile.write("id size acc_length cash\n")
for i in range(0, 101):
    size = random.randint(1, 5)
    acc = random.randint(2, 14)
    cash = random.randint(acc*100, acc*1000)
    gfile.write(f"{i} {size} {acc} {cash}\n")

gfile.close()
