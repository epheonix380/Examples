#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "assignment2.h"

/*

Code created by epheonix380: https://github.com/epheonix380
This code is intended to be used as an example for a dictionary system in 
C that is saved to a file.

*/

int add_term(const char* file_name, const char* word, const char* definition) {
    /*
    Most of the code related to file handeling was taken from this website:
    https://www.programiz.com/c-programming/c-file-input-output


    Most of the code related to strtok was taken from this weksite:
    https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    */

    // Gets file and opens it
    FILE * fPtr;
    fPtr = fopen(file_name, "a+");
    if(fPtr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Gets data from file as string
    char* data[1024];
    fgets(data,1024, fPtr);

    // Gets tokes from string as string using strtok
    char *token;
    char *def;
    token = strtok(data, "|");

    // Checks to see if word is already in the file
    int isContained = 0;
    while( token != NULL ) {
      def = strtok(NULL, "|");
      if (strcmp(token, word) == 0) {
        isContained = 1;
        break;
      }
      token = strtok(NULL, "|");
    }
    
    // If word is in file returns 0 else puts word and def in file
    if (!isContained) {
      fputs(word, fPtr);
      fputs("|", fPtr);
      fputs(definition, fPtr);
      fputs("|", fPtr);
    } else {
      fclose(fPtr);
      return 0;
    }
    // Close file to save file data and returns 1
    fclose(fPtr);
    return 1;
}  



char* find_term(const char* file_name, const char* word) {
        /*
    Most of the code related to file handeling was taken from this website:
    https://www.programiz.com/c-programming/c-file-input-output


    Most of the code related to strtok was taken from this weksite:
    https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    */
     // Gets file and opens it
    FILE * fPtr;
    fPtr = fopen(file_name, "a+");
    if(fPtr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Gets data from file as string
    char* data[1024];
    fgets(data,1024, fPtr);

    // Gets tokes from string as string using strtok
    char *token;
    char *def;
    token = strtok(data, "|");

    // Checks to see if word is already in the file
    int isContained = 0;
    while( token != NULL ) {
      def = strtok(NULL, "|");
      if (strcmp(token, word) == 0) {
        isContained = 1;
        break;
      }
      token = strtok(NULL, "|");
    }

    // If word is in dictionary returns the def else returns NULL
    if (isContained) {
      char * answer = malloc(strlen(def)*sizeof(char));
      strcpy(answer, def);
      return answer;
    } else {
      return NULL;
    }

  
}  