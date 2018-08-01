//
//  main.cpp
//  rotatematrixC++
//
//  Created by Katelyn Suhr on 7/9/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>
using namespace std;
const int MATRIX_SIZE =  4 ;

void printMatrix(int m[MATRIX_SIZE][MATRIX_SIZE])
{
    cout<<" "<< endl;
    for(int i = 0; i < MATRIX_SIZE; ++i){
        for(int j = 0; j < MATRIX_SIZE; ++j){
            cout<<m[i][j];
            if(m[i][j] <10) cout << "      ";
            else if(m[i][j] < 100) cout<<"     ";
            else cout << "    ";
                
            

        }
        cout << endl;
    }
    cout <<" ------------------------------------" << endl;
    
}

void swap(int& i, int& j){
    int temp = i; //i is a reference to temp
    i = j;
    j = temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int m[MATRIX_SIZE][MATRIX_SIZE];
    int count = 0;
    int last = MATRIX_SIZE -1;
    int level = 0;
    int totNumOfLevels = MATRIX_SIZE / 2 ;
    
    for(int i = 0; i < MATRIX_SIZE; ++i){
        for(int j = 0; j < MATRIX_SIZE; ++j){
            m[i][j] = count++;
        }
    }
    cout<< "---------- Original Matrix ----------"<< endl;
    printMatrix(m);
    while(level < totNumOfLevels){
        for(int i = level; i < last; ++i){
            swap(m[level][i], m[i][last]);
            swap(m[level][i], m[last][last - i + level]);
            swap(m[level][i], m[last -i + level][level]);

        }
        ++level;
        --last;
    }
    cout<< "---------- Rotated Matrix ----------"<< endl;
    printMatrix(m);
    
   // return 0;
}
