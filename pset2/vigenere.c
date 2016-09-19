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

    int k = 0;
    int len_key = strlen(argv[1]);

    //modify a key, if key contain non-alphabetical characters return ERORR
    for (int i=0;i<len_key;i++)
    {
        if (isalpha(argv[1][i]))
        {
            if (isupper(argv[1][i]))
            {
                argv[1][i]-=65;
            } else
            {
                argv[1][i]-=97;
            }
        } else
        {
            printf("Erorr\n");return 1;
        }
    }

    printf("plaintext: ");
    string text = GetString();
    
    printf("ciphertext: ");
    for (int i=0, len=strlen(text);i<len;i++)
    {
        if(isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                printf("%c", (((text[i]-64)+(argv[1][k]))%26)+64);
                if(k<=len_key-2)
                {
                    k++;
                } else
                {
                    k = 0;
                }
            }
            else
            {
                printf("%c", (((text[i]-96)+(argv[1][k]))%26)+96);
                if(k<=len_key-2)
                {
                    k++;
                } else
                {
                    k = 0;
                }
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