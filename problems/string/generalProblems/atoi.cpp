// https://leetcode.com/problems/string-to-integer-atoi/description/
#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s)
{
    int sign = 1; // neural sign of number
    int i = 0;    // index of the character of the string
    while (s[i] == ' ')
        i++;

    // let's consider whether the number is neg or positive according to the sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    int n = 0;                                         // use that to convert the string into number
    while (s[i] >= '0' && s[i] <= '9' && i < s.size()) // get the numbers only
    {
        n = n * 10 + (s[i] - '0'); // get the whole number
        i++;
        // overflow case
        if (n > INT_MAX)
            return sign == 1 ? INT_MAX : INT_MIN;
    }

    return (int)(sign * n);
}

// recursive approach

long myAtoi(int i, int sign, string s, long result)
{
    // Check if the integer is about to overflow.
    if (sign * result >= INT_MAX)
    {
        // If the integer is about to overflow, return INT_MAX.
        return INT_MAX;
    }
    else if (sign * result <= INT_MIN)
    {
        // If the integer is about to overflow, return INT_MIN.
        return INT_MIN;
    }

    // Check if we have reached the end of the string or if the next character is not a digit.
    if (i >= s.size() || s[i] < '0' || s[i] > '9') // any break of our conditions
    {
        // If we have reached the end of the string or if the next character is not a digit, return the result.
        return sign * result;
    }

    // Otherwise, add the next digit to the result and recursively call the function.
    result = result * 10 + (s[i] - '0');
    return myAtoi(i + 1, sign, s, result);
}

int myAtoi(string s)
{
    // The sign of the integer.
    int sign = 1;
    // The index of the current character in the string.
    int i = 0;

    // Ignore any leading whitespace.
    while (s[i] == ' ')
        i++;

    // Set the sign of the integer if the next character is '-' or '+'.
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    // Recursively convert the string to an integer.
    return (int)myAtoi(i, sign, s, 0);
}
