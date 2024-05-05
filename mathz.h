#pragma once

// Returns 10 to the power of exponent
int powz10(int exponent)
{
    if(exponent < 0 || exponent > 9) 
    {
        return 0;
    }
    
    int sum = 1;

    for(int i = 0; i < exponent; i++)
    {
        sum *= 10;
    }
    
    return sum;
}