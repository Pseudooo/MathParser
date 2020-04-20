#include <stdio.h>

/**
    Will return an integer based on char input
    1 - Input is a number
    0 - Input is not a number
*/
int is_number(char* str)
{
    if(str == NULL || str[0] == 0) // checking if input is empty
        return 0;

    if(str[0] == '-' && str[1] == 0) // checking if the input isn't just '-'
        return 0;

    int s = str[0] == '-' ? 1 : 0; // checking if first char is '-'
    
    for(int i = s;; i++) 
    {
        if(str[i] == 0) break; // terminator

        if(str[i] < '0' || str[i] > '9') 
        {
            return 0;
        }
    }

    return 1;
}

/**
    Will convert a string to an integer
    1 - Success
    0 - Invalid Number
   -1 - Empty String
*/
int from_str(char* str, int* dest)
{
    if(str == NULL || str[0] == 0) // checking if input is empty
        return -1;

    if(str[0] == '-' && str[1] == 0) // checking if the input isn't just '-'
        return 0;

    int s = str[0] == '-' ? 1 : 0; 
    char* cur = str+s; int out = 0; // skipping '-' at the beggining of input
    while(*cur != 0)
    {
        if(*cur < '0' || *cur > '9')
            return 0;

        out *= 10;
        out += *(cur++) - '0';
    }

    out *= s ? -1 : 1; // multiplying output by -1 if there is '-' at start of input
    *dest = out;
    return 1;
}

/**
    Given an integer value this function will create a string
    representation of it and place it in the given `dest`
*/
void to_str(int x, char* dest)
{

    int neg = x < 0 ? 1 : 0;
    if(neg) x *= -1;

    char buff[32]; int idx = 30;
    buff[31] = 0;
    do{
        char offset = x % 10;
        buff[idx] = '0' + offset;
        x -= offset;
        x /= 10;
        idx--;
    }while(x > 0);

    if(neg)
        buff[idx] = '-';
    else
        idx++;

    char* new = buff+idx;
    for(int i = 0;;i++)
    {
        dest[i] = new[i];
        if(new[i] == 0)
            break;
    }

}