import sys

if not(len(sys.argv) == 2):
    print("Erorr\n")
    exit(1)
    
if not(sys.argv[1].isalpha()):
    print("Erorr\n")
    exit(1)

text = input("plaintext: ")

k = 0

print("ciphertext: ", end = '')

for i in range(len(text)):
    if(text[i].isalpha()):
        if (text[i].isupper()):
            if(sys.argv[1][k].isupper()):
                print(chr((((ord(text[i])-64)+(ord(sys.argv[1][k])-65)))+64), end = '')
            else:
                print(chr((((ord(text[i])-64)+(ord(sys.argv[1][k])-97)))+64), end = '')
            if(k<=(len(sys.argv[1])-2)):
                k += 1
            else:
                k = 0
        else:
            if(sys.argv[1][k].isupper()):
                print(chr((((ord(text[i])-96)+(ord(sys.argv[1][k])-65)))+96), end = '')
            else:
                print(chr((((ord(text[i])-96)+(ord(sys.argv[1][k])-97)))+96), end = '')
            if(k<=(len(sys.argv[1])-2)):
                k += 1
            else:
                k = 0
    else:
        print(text[i], end = '')
        
print('\n')