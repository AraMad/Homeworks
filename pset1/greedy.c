#include <stdio.h>
#include <cs50.h>
#include <math.h>

// array with nominals of coins
const int NOMINALS[] = {1, 5, 10, 25};

int main(void)
{
    float change;
    
        do
        {
            printf("O hai! How much change is owed?\n");
            change = GetFloat();
            
        } while(change < 0);

    int amount_coin = 0;
    
    int rest = (round(change*100));
    
        while (rest != 0) 
        {
            if (rest >= NOMINALS[3])
            {
                rest -= 25;
                amount_coin++;
            } else
            {
                if(rest >= NOMINALS[2])
                {
                    rest -= 10;
                    amount_coin++;
                } else
                {
                    if(rest >= NOMINALS[1])
                    {
                        rest -= 5;
                        amount_coin++;
                    } else
                    {
                        if(rest >= NOMINALS[0])
                        {
                            rest -= 1;
                            amount_coin++;
                        }
                    }
                }
            }
        }
        
    printf("%d\n", amount_coin);
    return 0;
}