# Digits

let's see a very basic and important thing when dealing with digits.

## Digit extraction

###  basic rule keep it in your mind is this : 

- to extract the last digit -> take the mod of the number
- keep dividing the number by 10 to get the remaining digits.

## pseudo code:

`while(n>0)
    {
        lastDigit=lastDigit*10 + n%10;
        n=n/10;
    }`

    