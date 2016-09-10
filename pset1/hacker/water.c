#include <stdio.h>
#include <cs50.h>

const int BOTTLES_IN_MINUTE = 12;

int main(void) {
    int minutes;
        do 
        {
            printf("minutes: ");
            minutes = GetInt();
            
        } while (minutes <= 0);
        
    printf("bottles: %d\n", minutes*BOTTLES_IN_MINUTE);
    
    return 0;
}