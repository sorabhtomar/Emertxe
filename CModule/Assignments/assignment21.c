/*  Q. Recursive factorial without using any 
 *   other function than main
 *
 *  a. Read number n from user.
 *  b. Call main function from main for calculating factorial.
 *  c. Prompt for continue option.
 *
 *  Hint: Use static variables.
 *
 *  Prerequisites:
 *  --------------
 *  Recursive function concepts.
 *  Static storage class concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter n: 7
 *
 *  Factorial of 7: 5040
 *
 *  Continue (y/n):
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    static int returnValue, flag = 1, num, n, temp =1;
	
	if(flag)
    {
        printf("Enter n: ");
        scanf("%d", &num);
		flag = 0;
	}	
	
	temp = temp * num--;

	/* check for initial valid number */
    if (num < 1)
    {
		printf("Factorial: %d \n", temp);
        return 0;
    }
    else
    {
		main();
	}
    
}


