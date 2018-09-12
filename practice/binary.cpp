#include<iostream>
#include<string.h>
using namespace std;

//declare functions
void printBinary(int k);
void formBinary(int k, string s);

void printBinary(int k)
{
    formBinary(k, "");
}

void formBinary(int k, string s)
{
    if(s.length() == k)
    {
        string str1 = "11";
        size_t found = s.find(str1);
        //if not matches are found, the function returns npos
        if(found == std::string::npos)
        {
            cout << s << endl;
        }
        else
        {
            cout << "found: " << s << endl;

        }

    }
    else
    {
        formBinary(k,s+"0");
        formBinary(k,s+"1");

    }

}



int main(int argc, const char * argv[])
{

    printBinary(2);

    return 0;
}
