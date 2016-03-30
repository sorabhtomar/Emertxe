/* Function Prototypes and Definitions to do number
 *  manipulations 
 *  
 *  functions in ntype library.
 *
 *      -> int my_ispositive(int var);
 *      -> int my_iszero(int var);
 *      -> int bin2dec(char binary[], int bits);
 *      -> void print_Menu(char sptr[][MAX_COL], int rows);
 *      -> void fibonacci(int givenNum);
 *      -> int itoa(int n, char *s);
 *      -> void itob(int n, char *s, int b);
 */

#include <stdio.h>
#include <string.h>
#define MAX_COL 10000

/*
 * To check if the passed value is positive number or not.
 * If true returns 1 else 0
 */
int my_ispositive(int var)
{
    if( (var*-1) < 0 )
    {
        return 1;
    }
    return 0;
}

/*
 * To check if the passed value is zero or not.
 * If true returns 1 else 0
 */
int my_iszero(int var)
{
    if( var == 0 )
    {
        return 1;
    }
    return 0;
}

/* To convert from binary to decimal
 */
int bin2dec(char binary[], int bits)
{
    int i, decimal = 0;
    int bitval = 0, mask = 1;
    
    for (i = 0; i < bits; i++)
    {
        if ((*(binary + bits - i - 1)) == '1')
        {
            bitval = 1;
        }
        else
        {
            bitval = 0;
        }
    
        decimal += (bitval * (mask<< i) );
    }
    return decimal;
}

/* To print Menu */
void print_Menu(char sptr[][MAX_COL], int rows)
{
    int i;
    
    for (i = 0; i < rows; i++)
    {
        printf("%d %s \n", i+1, *(sptr+i));
    }
}

/* Recursive fibonacii function */
/* generate the fibonacii numbers <= givenNum */
void fibonacci(int givenNum)
{
    /* initial values */
    static long int fib1=0, fib2=1, temp;
    
    while (fib1 <= givenNum)
    {
        printf("%ld ", fib1);
        /* take the first fib into temp */
        temp = fib1;
        /* fib1 will be sum of fib1 and fib2 */
        fib1 += fib2;
        /* fib2 will be the value of previous fib1 value */
        fib2 = temp;
        /* recursively call the fibonacii function */
        fibonacci( givenNum - 1 );
    }
    
}

/*  a. Convert integer n into a string and store the string in s.
 *  b. Return the length of string from the function.
 */
int itoa(int n, char *s)
{
    int count = 0, temp, i;
    
    /* Check for buf size */
    if(s == NULL)
    {
        return 0;
    }
    
    /* if number is 0 then just give zero */
    if(n == 0)
    {
        *s = '0';
        return 1;
    }
    
    /* if num is negative int */
    if(n < 0)
    {
        n *= (-1); /* make the num positive for next evaluation */
        *s++ = '-'; /* store the '-' in s[0] and */
        count++; /* increment count for string length */
    }
    
    /* to acess s buf from s[n-1] where n is the number of digits and also to add null at nth place */
    for(temp = n; temp > 0; temp /= 10, s++);
    *s = '\0';
    
    /* fill the ASCII value of each digit by getting from lsb into s[n-1] --> s[0] place */
    for(temp = n; temp > 0; temp /= 10)
    {
        
        *--s = temp % 10 + '0';
        count++; /* increment the str len */
    }
    
    
    /* returns the string len */
    rewind(stdin);
    return count;
    
}

/* Converts n value into it's base value and stores in String
 *
 */
void itob(int n, char s[], int b)
{
    int i, sign;
    int temp, j;
    
    char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (2 > b || b > strlen(symbols) )
        return;     /* not a valid base */
    
    sign = n;
    i = 0;
    do {            /* generate symbols in reverse order */
        s[i++] = symbols[abs(n % b)];   /* get next symbols */
    } while (n /= b);                   /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

