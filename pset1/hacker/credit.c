# include <stdio.h>
# include <cs50.h>

//return lenght of card number
int lenghtOfCardNumber(long long number);
//return type of card (AMEX\n, MASTERCARD\n, VISA\n) or INVALID\n if no match is found
char* typeOfCard(long long number, int lenght);
//return TRUE if card is valid, else FALSE
bool isValid(long long num, int lenght_number);
//return TRUE if card number is valid, else FALSE
bool isValidLenght(int lenght);

int main(void)
{
    long long cardNumber;
    
    do 
    {
        printf("Number: ");
        cardNumber = GetLongLong();
        
    } while(cardNumber < 0);
    
   int lenghtOfnumber = lenghtOfCardNumber(cardNumber);
   
   if (!isValidLenght(lenghtOfnumber))
   {
       printf("INVALID\n");
       return 0;
   }
   
   if (!isValid(cardNumber, lenghtOfnumber))
   {
       printf("INVALID\n");
       return 0;
   }
   
   printf("%s", typeOfCard(cardNumber, lenghtOfnumber));
   
   return 0;
}

int lenghtOfCardNumber(long long number){
    int lenght = 0;
    
    while (number)
    {
        number /= 10;
        lenght++;
    }
    
    return lenght;
}

bool isValid(long long num, int lenght_number){
    
    int number[lenght_number];

    for (int i = lenght_number - 1; i >= 0; i--)
    {
        number[i] = num % 10;
        num /= 10;
    }
    
    int controlSum = 0;
    bool isSecond = 0;
    
    for (int i = lenght_number-1; i <= 0 ; i--)
    {
        if (isSecond)
        {
            if ((number[i] * 2) > 9)
            {
                 number[i] = ((number[i] * 2) % 10) + ((number[i] * 2) / 10);
            }
            number[i] *= 2;
            isSecond = 0;
        }
        controlSum += number[i];
        isSecond = 1;
    }
    
    if (controlSum % 10 == 0) {return 1;}
    
    return 0;
}

bool isValidLenght(int lenght){
    
    const int LENGHT_OF_ARRAY = 3;
    const int LENGHTS[] = {13, 15, 16};
    
    for (int i = 0; i < LENGHT_OF_ARRAY; i++)
       {
            if(lenght == LENGHTS[i])
            {
                return 1;
            }
       }
    
    return 0;
}

char* typeOfCard(long long number, int lenght){
    
    // go to the fist 2 numbers
    for (int i = 0; i < lenght - 2; i++)
    {
        number /= 10;
    }
    
    switch (number)
    {
        case 34: return "AMEX\n";
        case 37: return "AMEX\n";
        case 51: return "MASTERCARD\n";
        case 52: return "MASTERCARD\n";
        case 53: return "MASTERCARD\n";
        case 54: return "MASTERCARD\n";
        case 55: return "MASTERCARD\n";
        default: return ((number / 10) == 4) ? "VISA\n":"INVALID\n";
    }
}