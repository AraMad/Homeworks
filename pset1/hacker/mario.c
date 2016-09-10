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
        
    } while (height < MIN_HEIGHT || height >MAX_HEIGHT);
    

        int hashInLine = 1;
        
        for (int i = 0; i < height; i++)
        {
            for (int k = 0; k < (height - hashInLine); k++)
            {
                printf(" ");
            }
            for (int k = 0; k < hashInLine; k++)
            {
                printf("#");
            }
            
            printf("  ");
            
            for (int k = 0; k < hashInLine; k++)
            {
                printf("#");
            }
            
            printf("\n");
            hashInLine++;
        }
        
    return 0;
}