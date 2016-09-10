#include <stdio.h>
#include <cs50.h>

const int BOTTLES_IN_MINUTE = 12;

int main(void) {
    
    printf("minutes: ");
    
    int minutes = GetInt();
    
    printf("bottles: %d\n", minutes*BOTTLES_IN_MINUTE);
    
    return 0;
}