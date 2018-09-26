#include <iostream>
#include <string>
#include <fstream> //file streams
#include <vector>
#include <sstream> //std::istringstream
using namespace std;

vector<string> missingWords(string s, string t)
{
    vector<string> result1;
    vector <string> result2;

    istringstream sval(s);
    istringstream tval(t);

    string buffer;
    //way 1 to store words into vector
    while(sval >> buffer)
    {
        result1.push_back(buffer);
    }

    //way 2 to store words into vector
    for(string n; tval >> n;)
    {
        result2.push_back(n);
    }

    vector <string> sentence;

    int j = 0;
    for(int i = 0; i < result1.size(); i ++)
    {
        if(result1[i] == result2[j])
        {
            j++;
        }
        else
        {
            sentence.push_back(result1[i]);
        }
    }

    return sentence;    
}



int main(int argc, const char * argv[])
{
    string s = {"I like eating cheese do you like cheese"};
    string t = {"like cheese"};

    vector<string> res = missingWords(s, t);

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i]<< endl;
    }

    return 0;
}
