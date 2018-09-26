#include <iostream>
#include <string>
#include <vector>

using namespace std;

//declare functions
void findSubstrings(string s);
bool isVowel(char c);


void findSubstrings(string s)
{

    vector<string> pos;
    string word = "";
    //int j = 1;
    for(int i = 0; i < s.size(); i++)
    {
        word = s[i];
        //check if first letter is a vowel
        if(isVowel(word[0]))
        {
            int j = i+1;
            while(j < s.size())
            {
                word+= s[j];
                int last = word[word.size()-1];
                //check if last letter of substring is a constant
                if(!isVowel(last))
                {
                    pos.push_back(word);
                }
                j++;
            }
            word = "";
        }
    }

    string first = "";
    string end = "";

    if(pos.size() > 2)
    {
        first = pos[0];
        end = pos[pos.size()-1];
        cout << first<< endl;
        cout << end << endl;
    }
    else
    {
        cout << pos[0] << endl;
        cout << pos[0] << endl;
    }
    
}

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main()
{
    string s = {"aabd"};
 //   getline(cin, s);

    findSubstrings(s);

    return 0;

}
