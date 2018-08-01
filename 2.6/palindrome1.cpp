//
//  main.cpp
//  2.6
//
//  Created by Katelyn Suhr on 7/30/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.

//palindrome


#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>

using namespace std;

//strings are arrays of characters


//passing in copy of integer
//pass in copy
void passByVal(int val);
//pass integer value by reference
//pass in actual variable
void passByRef(int &ref);
void passByPtr(int *ptr);

class Palindrome
{
public:
    static bool isPalindrome(const string& word)
    {
        string copy = "";
        int max_length = (int) word.length();
        for(int i = max_length; i >= 0; i--)
        {
            copy = copy + word[i];
        }
        
        char c;
        int i = 0;
        
        while(copy[i])
        {
            c = copy[i];
            putchar(tolower(c));
            i++;
        }
        cout << "copy: " << copy;
        cout << " \n";
        bool equal = false;
        for(int j = 0; j < word.length(); j++)
        {
            if(word[j] == copy[j])
            {
                equal = true;
            }
            else
            {
                equal = false;
            }
            
        }
        
        return true;
        //throw logic_error("Waiting to be implemented");
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << Palindrome::isPalindrome("Deleveled");
    
//    string s1("Hampster");
//    string s2;
//    string s3;
    
//    s2 = s1;
//    s3.assign(s1);
//    cout << s1 << s2 << s3 << endl;

    
//    string s1 = "omghdka";
//    cout << "String is: ";
//    cout << s1.at(3);
//    for(int x = 0; x < s1.length(); x++)
//    {
//        cout << s1.at(x);
//    }
//    cout << "\n";
    
    
    
//    int x  = 5;
//    int *xptr = &x;
//    printf("x = %i \n", x);
//    printf("*xptr = %i\n", *xptr);
//    passByPtr(xptr);
//    printf("x = %i \n", x);
//    printf("*xptr = %i\n", *xptr);
    
    
//    printf("x = %i\n", x);
//    passByVal(x);
//    printf("x = %i\n", x);
//    passByRef(x);
//    printf("x = %i\n", x);
    return 0;
}
void passByVal(int val)
{
    val = 10;
    printf("val = %i \n", val);
}
//actually passing in variable
//variable changes
void passByRef(int &ref)
{
    ref = 20;
    printf("ref = %i \n", ref);
}
void passByPtr(int *ptr)
{
    *ptr = 30;
    printf("*ptr = %i \n", *ptr);
}
