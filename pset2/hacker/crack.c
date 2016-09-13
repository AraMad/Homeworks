#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

const int AMOUNT_OF_LETTERS = 26;
const int LENGHT_OF_PASSWORD = 5;
const int DIFFERENCE_LOW = 97;
const int DIFFERENCE_UP = 65;
bool isPasswordFound(char *hash);

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Erorr\n");
        return 1;
    }
    
    //printf("%s\n", crypt("hypo", "50")); 50T6zjKyyx4dw
    
    if (isPasswordFound(argv[1]))
    {
        return 0;
    }
    
    printf("Not found\n");
    
    return 0;
}

bool isPasswordFound(char *hash)
{
    
    char password_low[LENGHT_OF_PASSWORD];
    char password_up[LENGHT_OF_PASSWORD];
    password_low[4] = '\0';
    password_up[4] = '\0';

   for (int i = 0; i < AMOUNT_OF_LETTERS; i++)
    {
        password_low[0] = i + DIFFERENCE_LOW;
        password_up[0] = i + DIFFERENCE_UP;
        for (int l = 0; l < AMOUNT_OF_LETTERS; l++)
        {
            password_low[1] = l + DIFFERENCE_LOW;
            password_up[1] = l + DIFFERENCE_UP;
            for (int k = 0; k < AMOUNT_OF_LETTERS; k++)
            {
                password_low[2] = k + DIFFERENCE_LOW;
                password_up[2] = k + DIFFERENCE_UP;
                for (int j = 0; j < AMOUNT_OF_LETTERS; j++)
                {
                    password_low[3] = j + DIFFERENCE_LOW;
                    password_up[3] = j + DIFFERENCE_UP;
                    if (!strcmp(crypt(password_low, "50"),  hash))
                    {
                         printf("%s\n", password_low);
                         return 1;
                    }
                    if (!strcmp(crypt(password_up, "50"),  hash))
                    {
                         printf("%s\n", password_up);
                         return 1;
                    }
                }
            }
        }
    }
    return 0;
}