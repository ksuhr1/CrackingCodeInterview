#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{

public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int maxlength = 0;
        string result = "";
        result = s[i];
        string finalstr = "";
             
            for(int j = i+1; j <= s.length(); j++)
            {
               if(result.length() > maxlength)
               {
                   maxlength = result.length();
                   finalstr = result;
               }
               //if it didn't find the value in the string-
               //concatenate
               if(result.find(s[j]) == std::string::npos)
               {    
                   result +=s[j]; 
               }
               else
               {
                   if(s[j] == s[j-1])
                    {
                       result = s[j];
                       i = j;
                    }
                    else
                    {
                                                
                       i++;
                       result = s[i];
                       j = i;
                   }
                  
              }
            
            }

        cout << "the longest substring is: " << finalstr <<", " << maxlength<< endl;
        return maxlength;
    }


};



int main(int argc, const char *argv[])
{

    Solution s;
    string str = "pwwkewa";
  // string str = " ";
    s.lengthOfLongestSubstring(str);



    return 0;
}
