# +++++++++++++++++++++++++++++++++
# program, that draw a half-pyramid
# +++++++++++++++++++++++++++++++++

height = 0
# ask user to input a height of pyramid and check his input
while height <= 0 or height > 23:
    try:
        height = int(input("height: "))
    except ValueError:
        continue

hashInLine = 2

# print a half-pyramid
i = height
while i > 0:
    print(" "*(i-1), "#"*hashInLine)
    hashInLine+=1
    i-=1