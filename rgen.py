from locale import format_string
import random

from numpy import choose
slist = ["normal", "apartament", "studio"]
rfile = open("rooms.txt", "w")
rfile.write("id type number_of_beds area fee additional_furniture\n")
for i in range(0, 101):
    type = random.choice(slist)
    nob = random.randint(1, 5)
    area = nob*8 + random.randint(8, 20)
    addi = random.randint(0, 1)
    fee = area + addi*15 +  random.randint(10, 40)
    rfile.write(f"{i}   {type}   {nob}  {area}   {fee}  {addi}\n")

rfile.close()