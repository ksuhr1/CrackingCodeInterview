//
//  main.c
//  zeromatrix
//
//  Created by Katelyn Suhr on 7/11/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define COL 4
#define ROW 3

void printMatrix(int m[ROW][COL]);
int findZeros(int m[ROW][COL], int row[ROW], int col[COL]);
void replaceWithZeros(int m[ROW][COL], int row[ROW], int col[COL]);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int m[ROW][COL] = {5,6,7,8,9,10,11,12,13,14,0,16};
    //int count = 0;
    
    //create two temporary arrays
    int row[ROW];
    int col[COL];
    
    // fill main matrix

//    for(int i = 0; i < ROW; i++ ){
//        for(int j = 0; j < COL; j++){
//            m[i][j] = count;
//            count++;
//        }
//    }
    
    //fill temporary arrays with 0
    for(int i = 0; i < ROW; i++ ){
            row[i] = 1;
           printf("%d", row[i]);
    }
    
    for(int i = 0; i < COL; i++ ){
        col[i] = 1;
    }
    printf("---------- Original Matrix ---------- \n");
    printMatrix(m);
    findZeros(m, row, col);
    replaceWithZeros(m, row, col);
    printf("---------- New Matrix ----------- \n");
    printMatrix(m);
    
     return 0;
}

//replace row,col of element that contains 0
void replaceWithZeros(int m[ROW][COL], int row[ROW], int col[COL]){
    for(int i = 0 ; i < ROW; i++){
        for(int j = 0; j< COL; j++){
            if(row[i] == 0 || col[j] == 0){
                m[i][j] = 0;
            }
            
        }
    }
}

//place 0 in temporary arrays in same spot as main array
//find the i,j element that contians a 0
int findZeros(int m[ROW][COL], int row[ROW], int col[COL]){
    for(int i = 0; i < ROW; i++ ){
        for(int j = 0; j < COL; j++){
            if(m[i][j] == 0){
                row[i] = 0;
                col[i] = 0;
                printf("Found a zero at: %d, %d \n", i,j);
        
            }
        }
    }
    return 0;
}

//utility function to print a matrix
void printMatrix(int m[ROW][COL]){
    for(int i = 0; i < ROW; i++ ){
        for(int j = 0; j < COL; j++){
            if(m[i][j] < 10) printf("%d     ", m[i][j]);
            else if(m[i][j] < 100) printf("%d    ",m[i][j]);
            else printf("%d   ",m[i][j]);
        }
        printf("\n");
    }
    
}
