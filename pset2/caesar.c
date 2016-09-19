#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

//function that cipher text
char *crypt(char *text, int key);

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Erorr\n");
        return 1;
    }
    
    //modify a key for more comfortable usage
    int key = atoi(argv[1]) <= 26 ? (atoi(argv[1])):(atoi(argv[1])%26);
    
    printf("plaintext: ");
    string text = GetString();

    printf("ciphertext: %s\n", crypt(text, key));
    
    return 0;
}

char *crypt(char *text, int key)
{
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i])) 
        {
            if (isupper(text[i]))
            {
                text[i] = (((text[i]-64)+key)%26)+64;
            }
            else
            {
                text[i] =  (((text[i]-96)+key)%26)+96;
            }
        }
    }
    return text;
}