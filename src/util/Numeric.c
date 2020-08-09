#include <stdio.h>
#include "Numeric.h"

/**
    Will return a truthy to determine if the provided
    string is a number
    1 - Input is a number
    0 - Input is not a number
*/
int is_integer(char* str)
{

    // Check if the given string is empty/null
    if(str == NULL || str[0] == 0)
        return 0;

    // Checking the edge-case of a single hypen being given
    if(str[0] == '-' && str[1] == 0)
        return 0;

    // Setting the start point to be after potential hypen
    int start = str[0] == '-' ? 1 : 0;
    
    for(int i = start;; i++) 
    {

        if(str[i] == 0) break; // terminator

        // Check if the current character is valid
        if(!is_digit(str[i])) 
            return 0;

    }

    // If end reached has to be a number
    return 1;
}

/*
    Check if a given character is a digit or not
*/
int is_digit(char c)
{
    return !(c < '0' || c > '9');
}

/**
    Will convert a string to an integer
    value is then returned as is_integer can
    be utilized for validating
*/
int from_str(char* str)
{

    // Edge case of empty string
    if(str == NULL || str[0] == 0)
        return -1;

    // Checking edge case of input being '-'
    if(str[0] == '-' && str[1] == 0)
        return -1;

    int start = str[0] == '-' ? 1 : 0; 
    char* cur = str+start; // skipping '-' at the beggining of input
    int out = 0; 
    while(*cur != 0) 
    {

        // Check value (To avoid horrific errornous values)
        if(!is_digit(*cur))
            return 0;

        // Accomodate current char
        out *= 10;
        out += *(cur++) - '0';
    }

    // Make output negative if str started with '-'
    out *= start ? -1 : 1;
    return out;
}

/**
    Given an integer value this function will create a string
    representation of it and place it in the given `dest`
*/
void to_str(int x, char* dest)
{

    // Determine if val is negative
    int neg = x < 0 ? 1 : 0;
    if(neg) x *= -1;

    /*
        Unsigned Integer is 32 bits, meaning a max value of
        2^32 (4.29*10^9) Which will have a maximum of 10 digits
        1 character for a '-' if negative and ending 0.
        Maximum of 12 characters
    */
    char buff[12]; int idx = 11;
    buff[11] = 0; // Set end to be 0
    
    do{

        // Take ending digit into string
        char offset = x % 10;
        buff[idx] = '0' + offset;
        
        // Adjust int value and index
        x -= offset;
        x /= 10;
        idx--;

    }while(x > 0);

    // Shift index to include hypen
    if(neg)
        buff[idx] = '-';
    else
        idx++;

    // Copy generated string to provided pointer
    char* new = buff+idx;
    for(int i = 0;;i++)
    {
        dest[i] = new[i];
        if(new[i] == 0)
            break;
    }

}