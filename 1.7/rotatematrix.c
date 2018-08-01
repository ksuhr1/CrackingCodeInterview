//
//  main.c
//  rotatematrix
//
//  Created by Katelyn Suhr on 7/9/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define MATRIX_SIZE 5
#define TRUE 1
#define FALSE 0

void printMatrix(int m[MATRIX_SIZE][MATRIX_SIZE]);
bool rotateMatrix(int m[MATRIX_SIZE][MATRIX_SIZE]);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int m [MATRIX_SIZE][MATRIX_SIZE];
    int count = 0;
    
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            count++;
            m[i][j] = count;
        }
    }
    
    printf("---------- Original Matrix ---------- \n");
    printMatrix(m);
    rotateMatrix(m);
    printf("---------- Rotated Matrix ---------- \n");
    printMatrix(m);
    return 0;
}

void printMatrix(int m [MATRIX_SIZE][MATRIX_SIZE]){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            if(m[i][j] < 10) printf("%d     ", m[i][j]);
            else if(m[i][j] <100) printf("%d    ", m[i][j]);
            else  printf("%d    ", m[i][j]);
        }
        printf("\n");
    }
}

bool rotateMatrix(int m [MATRIX_SIZE][MATRIX_SIZE]){
    int layer = 0;
    int last = MATRIX_SIZE-1;
    
    while(layer < MATRIX_SIZE/2){
        for(int i = layer; i < last; i++){
            int top = m[layer][i];

            //top -> left
            //m[0][0] = m[2][0]
            // m[0][1] = m[1][0]
            m[layer][i] = m[last-i+layer][layer];
            //printf("%d ", m[0][i]);
            
            // left-> bottom
            //m[2][0] = M[2][2]
            //m[1][0] = m[2][1]
            
            m[last-i+layer][layer] = m[last][last-i+layer];

            //bottom->right
            //m[2][2] = m[0][2]
            //m[2][1] = m[1][2]
            m[last][last-i+layer] = m[i][last];
            
            //right->top
            //m[0][2] = m[0][0]
            //m[1][2] = m[0][1]
            m[i][last] = top;
           
        }
        layer++;
        last--;
    }
    return TRUE;
}






