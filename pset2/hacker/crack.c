#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

const int LENGHT_OF_PASSWORD = 4;

bool isPasswordFound(char *hash);

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
    char salt[2] = {hash[0], hash[1]};
    char password[LENGHT_OF_PASSWORD];
    char buf[3];

   for (int i = 65; i < 123; i++)
    {
        if (i == 91) {i = 97;}
        password[0] = i;
        for (int l = 65; l < 123; l++)
        {
            if (l == 91) {l = 97;}
            password[1] = l;
            buf[0] = password[0]; buf[1] = password[1]; buf[2] = '\0';
            if (!strcmp(crypt(buf, salt),  hash))
                    {
                         printf("%s\n", buf);
                         return 1;
                    }
            for (int k = 65; k < 123; k++)
            {
                if (k == 91) {k = 97;}
                password[2] = k;
                buf[0] = password[0]; buf[1] = password[1]; buf[2] = password[2];
                if (!strcmp(crypt(buf, salt),  hash))
                    {
                         printf("%s\n", buf);
                         return 1;
                    }
                for (int j = 65; j < 123; j++)
                {
                    if (j == 91) {j = 97;}
                    password[3] = j;
                    if (!strcmp(crypt(password, salt),  hash))
                    {
                         printf("%s\n", password);
                         return 1;
                    }
                }
            }
        }
    }
    return 0;
}