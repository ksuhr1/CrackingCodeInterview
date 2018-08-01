//
//  main.c
//  Permutations
//
//  Created by Katelyn Suhr on 6/28/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char str1 [] = "abcde";
    char str2[] = "edbca";
    int val = 0;
    int letters [256];
    
//    for(int i = 0; i < strlen(str1); i++){
//        sum1 += str1[i];
//    }
//
//    for(int i = 0; i < strlen(str2); i++){
//        sum2 += str2[i];
//    }
//
    if(strlen(str1) != strlen(str2)){
        printf("The strings have different lengths \n");
    }
    
    for(int i=0; i< strlen(str1); i++){
        val = str1[i];
        letters[val]++;
    }
    
    for(int i=0; i< strlen(str2); i++){
        val = str2[i];
        letters[val]--;
        if(letters[val] < 0){
            printf("The strings are not permutations \n");
            return false;
        }
    }
    printf("%d \n", letters[val]);
    getchar();
}




