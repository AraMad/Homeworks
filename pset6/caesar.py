import sys

if not(len(sys.argv) == 2):
    print("Erorr\n")
    exit(1)
    
#modify a key for more comfortable usage
if int(sys.argv[1]) <= 26:
    key = int(sys.argv[1])
else:
    key = int(sys.argv[1])%26
    
text = input("plaintext: ")

#encrypt text
for i in range(len(text)):
    if(text[i].isalpha()): 
        if (text[i].isupper()):
            text = text.replace(text[i], chr((((ord(text[i])-64)+key)%26)+64), 1)
        else:
            text = text.replace(text[i], chr((((ord(text[i])-96)+key)%26)+96), 1)

print("ciphertext: ", text)