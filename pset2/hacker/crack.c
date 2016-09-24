#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// max lenght of password - 4 symbols
const int LENGHT_OF_PASSWORD = 5;
// iterates all possible combinations and compares theirs hashs with hash from parameters
// prints them and return true if found password
// else - false
bool isPasswordFound(char *hash);
// print password
void printPassword(char *password);

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Erorr\n");
        return 1;
    }
    
    if (isPasswordFound(argv[1]))
    {
        return 0;
    }
    
    printf("Not found\n");
    
    return 0;
}

bool isPasswordFound(char *hash)
{
    char salt[3] = {hash[0], hash[1], '\0'};
    char password[LENGHT_OF_PASSWORD];
    password[4] = '\0';
    char buf[4];
    buf[3] = '\0';

   for (int i = 'A'; i <= 'z'; i++)
    {
        if (i == ('Z'+1))
        {
            i = 'a';
        }
        
        password[0] = i;
        
        for (int l = 'A'; l < 'z'; l++)
        {
            if (l == ('Z'+1))
            {
                l = 'a';
            }
            
            password[1] = l;
            
            // check passwords of two characters
            {
                buf[0] = password[0];
                buf[1] = password[1];
                buf[2] = '\0';
                if (!strcmp(crypt(buf, salt),  hash))
                    {
                        printPassword(buf);
                        return 1;
                    }
            }
            
            for (int k = 'A'; k < 'z'; k++)
            {
                if (k == ('Z'+1))
                {
                    k = 'a';
                }
                
                password[2] = k;
                
                // check passwords of tree characters
                {
                    buf[0] = password[0];
                    buf[1] = password[1];
                    buf[2] = password[2];
                    if (!strcmp(crypt(buf, salt),  hash))
                    {
                        printPassword(buf);
                        return 1;
                    }
                }
                
                for (int j = 'A'; j < 'z'; j++)
                {
                    if (j == ('Z'+1))
                    {
                        j = 'a';
                    }
                    
                    password[3] = j;
                    
                    // check passwords of four characters
                    if (!strcmp(crypt(password, salt),  hash))
                    {
                        printPassword(password);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void printPassword(char *password)
{
    printf("%s\n", password);
}