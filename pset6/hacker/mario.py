# +++++++++++++++++++++++++++++++++++++++++++++++++++++
# program, that draw 2 half-pyramid separate with spase
# +++++++++++++++++++++++++++++++++++++++++++++++++++++

height = 0
# ask user to input a height of pyramid and check his input
while height <= 0 or height > 23:
    try:
        height = int(input("height: "))
    except ValueError:
        continue

hashInLine = 1

# print a half-pyramid
i = height
while i > 0:
    print(" "*(i-1), "#"*hashInLine, " ", "#"*hashInLine)
    hashInLine+=1
    i-=1