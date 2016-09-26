/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

#include <stdio.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int j = -1;
    
    if ((values[0] == value) || (values[n-1] == value))
    {
        return 1;
    }
   
    while (j < n-1)
    {
        if (values[(j+n)/2] < value)
        {
            j = (j+n)/2;
        }
        else
        {
            n = (j+n)/2;
        }
        if (values[n] == value)
        {
            return 1;
        }
    }
   
   return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++) 
    { 
        int min = values[i], k = i;
        
        for (int j = i; j < n; j++)
        {
            if (values[j] < min)
            {
                min = values[j]; k = j;
            }
        }
        
        values[k] = values[i];
        values[i] = min;
    }
}
