#include <stdio.h>
#include <cs50.h>

const int MIN_HEIGHT = 0;
const int MAX_HEIGHT = 23;

int main(void)
{
    int height;
    do 
    {
        printf("height: ");
        height = GetInt();
        
    } while (height < MIN_HEIGHT || height > MAX_HEIGHT);
    
        int hashInLine = 2;
        
        for (int i = height; i > 0; i--)
        {
            for (int k = 1; k < i; k++)
            {
                printf(" ");
            }
            
            for (int l = 0; l < hashInLine; l++){
                printf("#");
            }
            
            hashInLine++;
            printf("\n");
        }
        
    return 0;
}