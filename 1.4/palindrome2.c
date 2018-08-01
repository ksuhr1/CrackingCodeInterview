//
//  main.c
//  palindrome2
//
//  Created by Katelyn Suhr on 7/5/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

int getCharNumber(char c);
bool checkMaxOdd(uint8_t table[], int size);


int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "mom";
    uint8_t table [26];
    int x = 0;
    int countOdd = 0;
    
    //create frequency table
    for(int i=0; i<strlen(str); i++){
        // get character number
        x = getCharNumber(str[i]);
        if(x!= -1){
            table[x]++;
            printf("%d: %d \n", x, table[x]);
            if(table[x] % 2 == 1){
                //count odd
                
                countOdd++;
                printf("countOdd == 1: %d \n", countOdd);
            }
            else{
                //count     even
               
                countOdd--;
                printf("countOdd--: %d \n", countOdd);
            }
        }
    }
    printf("%d \n", countOdd);
    return countOdd <=1;
//    int size = sizeof(table)/sizeof(table[0]);
//    return checkMaxOdd(table, size);
}


// creates own mapping of each character a->0, b->1, c->2, etc.
int getCharNumber(char letter){
    //static int result;
    if((letter >= 97) && (letter <= 122)){
        return (letter-97);
    }
    return -1;
}

//bool checkMaxOdd(uint8_t table[], int size){
//    bool foundOdd = FALSE;
//    for(int i = 0; i < size; i++){
//        if(i % 2 == 1){
//          //   printf(" index %d : %d \n",i, table[i]);
//            if(foundOdd){
//                printf("found odd");
//                return FALSE;
//            }
//            foundOdd = TRUE;
//        }
//    }
//    return TRUE;
//}




