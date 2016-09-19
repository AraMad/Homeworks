#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;
    
    do
    {
        name = GetString();
    } while (name == NULL);
    
    char buf[3] ;
    int y = 0;
    
    for (int i = 0, n = strlen(name); i < n; i++) 
    {
        if ((i == 0) && (name[i] != ' '))
        {
            buf[y] = toupper(name[i]);
            y++;
        }
        if ((name[i] == ' ') && (name[i+1] != ' ')) 
        {
            buf[y] = toupper(name[i+1]);
            y++;
        }
    }
    
    printf("%s\n", buf);
}