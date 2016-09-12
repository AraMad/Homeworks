#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Erorr\n");
        return 1;
    }
    
    //
    int key = atoi(argv[1]) <= 26 ? (atoi(argv[1])):(atoi(argv[1])%26);
    
    printf("plaintext: ");
    string text = GetString();

    printf("ciphertext: ");
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i])) 
        {
            if (isupper(text[i]))
            {
                printf("%c", (((text[i]-64)+key)%26)+64);
                
            }
            else
            {
                printf("%c", (((text[i]-96)+key)%26)+96);
                
            }
        }
        else 
        {
            printf("%c", text[i]);
        }
    }
    
    printf("\n");
    return 0;
}