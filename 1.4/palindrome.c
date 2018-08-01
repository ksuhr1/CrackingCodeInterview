//
//  main.c
//  palindromes
//
//  Created by Katelyn Suhr on 7/3/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define lowerCaseMin 97
#define lowerCaseMax 122
#define upperCaseMin 65
#define upperCaseMax 90
#define foundOdd 0

int main(int argc, const char * argv[]) {
    // insert code here...
    char input [] = "tact coa";
    printf("Your string is %s \n", input);
    
    //need to form a palindrome
    int length = (int) strlen(input);
    char fwhitespace = FALSE;
    char upper = FALSE;
    char lower = FALSE;
    char doubleAmount = 0;
    char lowerCaseCount = 0;
    char upperCaseCount = 0;
    char spaceAmount = 0;
    int val = 0;
    int charArray [256];
   // char flengthEven;
    printf("The length is %d \n", length);
    
    for(int i = 0; i < length; i++)
    {
        val = input[i];
        charArray[val]++;

        //check for spaces
        if (val == 32){
            spaceAmount++;
        }
        // count double values
        if(charArray[val] == 2 && (val != 32) ){
            doubleAmount++;
        }
        // uppercase
        else if ((val >= 65) && (val <= 90)){
            upper = TRUE;
            // check for equivalent lowercase
            if(charArray[val+32] == 1){
                doubleAmount++;
            }
        }
        //lowercase
        else if((val >=97) && (val<= 122)){
            lower = TRUE;
            // check for equivalent uppercase
            if(charArray[val -32] == 1){
                doubleAmount++;
            }
        }
        printf("%c: %d \n", val, charArray[val]);
    }
    

    
    printf("doubleAmount: %d \n",doubleAmount);
    printf("spaceAmount: %d \n",spaceAmount);

    if(fwhitespace){
        printf("Found a whitespace \n");
    }
    
    return 0;
}
