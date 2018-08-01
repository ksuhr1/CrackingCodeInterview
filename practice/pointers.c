//
//  main.c
//  pointers
//
//  Created by Katelyn Suhr on 7/12/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 5;
    int *p = &x;
    
    *p = 6;
    
    int** q =&p;
    int*** r = &q;
    //prints 6
    printf("%d\n", *p);
    // printing p points to address of x
    printf("%d\n", p);
    //points to address of p that points to address of x
    printf("%d\n", *q);
    //6
    printf("%d\n", **q);
    //address of q which is address of p which is address of x
    printf("%d\n", **r);
    //6
    printf("%d\n", ***r);
    ***r = 10;
    //10
    printf("x = %d\n", x);
    //1606415934
    **q = *p +2;
    printf("x = %d\n", x);

   
}
