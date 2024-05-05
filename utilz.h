#pragma once

// Handles user input
int getUserInput()
{
    int sum = 0;
    char c[MAX_INPUT_SIZE + 2];

    fgets(c, sizeof(c), stdin);
    
    for(int i = 0; i < MAX_INPUT_SIZE + 2; i++)
    {
        if(c[i] == '\n' || c[i] == '\0')
        {
            if(i == 0) 
            {
                sum = -1;
            }
            else if(i < MAX_INPUT_SIZE + 1) 
            {
                sum = (int)(sum / 10);
                continue;
            }

            break;
        }

        if((int) c[i] < 48 || (int) c[i] > 57)
        {
            sum = -1;
            break;
        }

        sum += ((int) c[i] - 48) * powz10(MAX_INPUT_SIZE - i);
    }

    return sum;
}