#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*

Code created by epheonix380: https://github.com/epheonix380
This code is intended to be used as a library of sorts in C. The intention
was to replication the .split() functions available in Python, Javascript and more
The split function was intended to be the public facing function while the __count_tokens__
is designed to be a local helper function.

*/

int __count_tokens__(const char* str, const char* split) {

    /*
    !!!
    Most of the code related to strtok was taken from this weksite:
    https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    !!!
    */

    // String is duplicated for preservation
    char * token;
    char * def;
    char * dupstr[strlen(str)];
    strcpy(dupstr, str);

    // First token split is initialized
    token = strtok(dupstr, split);
    int count = 0;

    while( token != NULL ) {
      
      count = count + 1;
      /*
      int isLower = 1;
      for (int i = 0; i < strlen(token); i++) {
        if(islower(token[i])) {

        } else {
          isLower = 0;
        }
      }
      if (isLower == 1) {
        count = count + 1;
      }
      */
      token = strtok(NULL, split);
    }
  return count;
  
}  



char** split(const char* str, const char* split) {

    /*
    !!!
    Most of the code related to strtok was taken from this weksite:
    https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    !!!
    */
    char * token;
    char * def;
    char ** arr = (char**)malloc(sizeof(char*)*__count_tokens__(str, split));
    char * dupstr[strlen(str)];
    strcpy(dupstr, str);
    token = strtok(dupstr, split);
    int count = 0;


    while( token != NULL ) {
        /*
      int isLower = 1;
      for (int i = 0; i < strlen(token); i++) {
        if(islower(token[i])) {

        } else {
          isLower = 0;
        }
      }
      
      if (isLower == 1) {
        char * str_token = (char*)malloc(sizeof(char)*strlen(token));
        strcpy(str_token, token);
        arr[count] = str_token;
        count = count + 1;
      }
      */
        char * str_token = (char*)malloc(sizeof(char)*strlen(token));
        strcpy(str_token, token);
        arr[count] = str_token;
        count = count + 1;
        token = strtok(NULL, split);
    }
  return arr;
 
}  
