#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

const int AMOUNT_OF_LETTERS = 26;
const int LENGHT_OF_PASSWORD = 4;
const int DIFFERENCE = 97;
bool isPasswordFound(char *password, char *hash);

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Erorr\n");
        return 1;
    }
    
    //printf("%s\n", crypt("hypo", "50")); 50T6zjKyyx4dw
    
    char password[LENGHT_OF_PASSWORD];
    
   for (int i = 0; i < AMOUNT_OF_LETTERS; i++)
    {
        password[0] = i + DIFFERENCE;
        for (int l = 0; l < AMOUNT_OF_LETTERS; l++)
        {
            password[1] = i + DIFFERENCE;
            if (isPasswordFound(password, argv[1][0]))
            {
                return 0;
            }
        }
    }
    
    printf("Not found");
    
    return 0;
}

bool isPasswordFound(char *password, char *hash)
{
    
    for (int i = 0; i < AMOUNT_OF_LETTERS; i++)
    {
        password[2] = i + DIFFERENCE;
        for (int l = 0; l < AMOUNT_OF_LETTERS; l++)
        {
            password[3] = i + DIFFERENCE;
            if (!strcmp(crypt(password, "50"),  hash))
            {
                printf("%s\n", password);
                return 1;
            }
        }
    }
    return 0;
}