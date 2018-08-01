//
//  main.c
//  compression
//
//  Created by Katelyn Suhr on 7/6/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    char str[] = "aabbc";
    int size = (int)strlen(str);
    char buffer[256];
    int count = 0;
    
    //should check the length first
    for(int i = 0; i < size; i++){
        count++;
        // if not equal to neighbor, restart
        if((str[i] != str[i+1]) || ((i+1) >= size)){
           snprintf(buffer,size, "%c%d", str[i],count);
           // printf("%s",buffer);
           // printf("%c%d", str[i],count);
            if (strlen(buffer)< size){
                printf("%s", buffer);
            }
            else{
                printf("%s", str);
            }
            count = 0;
        }
    }
    
   
     printf("\n");
    return 0;
}
