//
//  main.c
//  modifystring
//
//  Created by Katelyn Suhr on 7/6/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

bool isStringEdit(char str1[], char str2[]);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char str1 [] = "bab";
    char str2 []= "ba";
    return isStringEdit(str1, str2);
}

bool isStringEdit(char str1[], char str2[]){
    int length1 = (int) strlen(str1);
    int length2 = (int) strlen(str2);
    int diff = 0;
    
    
    char freq [256];
    // create frequency table for each character
    for(int i = 0; i < length1; i++){
        freq[str1[i]]++;
    }
    
    // replace a character
    if(length1 == length2){
        printf("The strings are the same length \n");
        for(int i = 0; i < length1; i++){
            freq[str2[i]]--;
            printf("%c: %d \n", str2[i], freq[str2[i]]);
            
            if(freq[str2[i]] == -1){
                diff++;
            }
            
        }
    }
    // insert a character
    else if(length2 == length1+1){
        printf("String2 is longer \n");
        for(int i = 0; i < length2; i++){
            freq[str2[i]]--;
            printf("%c: %d \n", str2[i], freq[str2[i]]);
            
            if(freq[str2[i]] == -1){
                diff++;
            }
            
        }
        
    }
    //remove a character
    else if(length2 == length1-1){
        printf("String2 is shorter \n");
        for(int i = 0; i < length1; i++){
            freq[str2[i]]--;
            printf("%c: %d \n", str1[i], freq[str1[i]]);
            
            if(freq[str1[i]] == 1){
                diff++;
            }
        }
        
    }
    else{
        return diff;
    }
    printf("Difference is: %d \n", diff);
    if(diff <= 1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


