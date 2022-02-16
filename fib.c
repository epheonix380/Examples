#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "c_dictionary_example.c"

/*

Code created by epheonix380: https://github.com/epheonix380
This code is intended to be used as an example for a more efficient fib function
by saving the already processed data to a dictionary. This was based off a concept
introduced in UBC's CPSC221 course where Maps in C++ were used to make a more efficient
fib function. This was converted to C using the c_dictionary_example code that was created previously.

*/

uint64_t fib3(unsigned int n) {

    // Create numbers and strings for easy conversion between dictionary strings and ints
  uint64_t n1 = 0;
  uint64_t n2 = 0;
  uint64_t n3 = 0;
  char term1[3];
  char term2[3];
  char term3[3];
  char * num1;
  char * num2;
  char * num3;
  // Switch statement used to efficiently do the first 3 cases of the fib function
    switch (n)
    {
    case 0:
      return 0;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    default:
        
    // Converts the int n to string so that it can be searched in the dictionary
      sprintf(term1, "%u", n-1);
      sprintf(term2, "%u", n-2);
      sprintf(term3, "%u", n-3);

      // Attempts to find the numbers n in the dictionary
      num1 = find_term("fib.txt", term1);
      num2 = find_term("fib.txt", term2);
      num3 = find_term("fib.txt", term3);

      // If the number cannot be found in the dictionary the function does the 
      // calculations using recursive calls
      if (num1 == NULL) {
        n1 = fib3(n-1);
        char number1[50]; 
        sprintf(number1, "%u", n1);
        add_term("fib.txt",term1,number1);
      } else {
        n1 = atoi(num1);
      }
      if (num2 == NULL) {
        n2 = fib3(n-2);
        char number2[50]; 
        sprintf(number2, "%u", n2);
      } else {
        n2 = atoi(num2);
      }
      if (num3 == NULL) {
        n3 = fib3(n-3);
        char number3[50];
        sprintf(number3, "%u", n3);
      } else {
        n3 = atoi(num3);
      }

      // Does the arithmatic at the end 
      return n1 + 2*n2 + 3*n3;
      break;
    }
}



