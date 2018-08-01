//
//  main.c
//  URLify
//
//  Created by Katelyn Suhr on 7/2/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int urlify(char str[], int length);

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "Mr John Smith    ";
    int truelength = 13;
    int new_length = urlify(str, truelength);
    for(int i = 0; i< new_length; i++){
        printf("%c", str[i]);
    }
    getchar();
    return 0;
}

int urlify(char str[], int length){
    int numspaces = 0;
    for (int i = 0; i<length; i++){
        if (str[i] == ' '){
            numspaces +=1;
        }
    }
    
    int spaces = numspaces*2;
    int newlength = length+spaces;
 
    
    for(int j = newlength-1; j >= 0; j--){
        int pos = j-numspaces*2;
        if(str[pos] == ' '){
            str[j] = '0';
            printf("%d : %c \n", j,str[j]);
            str[j-1] = '2';
            printf("%d : %c \n", j-1,str[j-1]);
            str[j-2] ='%';
            printf("%d : %c \n", j-2,str[j-2]);
            numspaces--;
            j = j-2;
            
        }else{
            str[j] = str[pos];
            printf("%d: %c \n", j, str[j]);
           // pos--;
        }
    }
    return newlength;
  
}


