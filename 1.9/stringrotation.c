//
//  main.c
//  stringrotation
//
//  Created by Katelyn Suhr on 7/11/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

bool checkSubstring(char substr[], char s[]);
void findAllSubstrings(char str[], int size);



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char str[] ="apple";
    char substr[] = "ap";
    int size = (int)strlen(str);
    findAllSubstrings(str, size);
    checkSubstring(substr, str);
    
    return 0;
}

bool checkSubstring(char substr[], char str[]){
   // for(int i = 0; i <)
    
    
    return FALSE;
}

void findAllSubstrings(char str[], int size){
    int substr_size = (size*size+size)/2;
    //printf("Total number of substrings: %d", substr_size);
    //static char buffer[];
    char buffer[substr_size];

        //pick starting point
        for(int len = 1; len <= size; len++){
            for(int i = 0; i<= size-len; i++){
                
                //j is size of characters so if it's two,
                //print sequences of 2, etc.
                int j = i+len-1;
                // i, j and k  all match so it prints all single letters
                //all updated together
                for(int k = i; k<= j; k++){
                   // str[k];
                    snprintf(buffer, substr_size,"%c", str[k]);
                    //printf("%c", str[k]);
                }
               // printf("\n");
            }
        }
}
