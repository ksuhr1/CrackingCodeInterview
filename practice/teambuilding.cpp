#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//function calls and global variables
int teamHelper(vector<int> score, int team, int m);
bool sizeTeam(vector<int> ateam, int team);
vector<int>ateam;
long sum = 0.0;


bool sizeTeam(vector<int> ateam, int team)
{
    if(ateam.size() == team)
    {
               
        return true;
    }
    else
    {
        return false;
    }
}

long teamFormation(vector<int> score, int team, int m)
{
//    cout <<"ateam size: " << ateam.size()<< endl;
    if((score.size() == team) && (ateam.size()== team))
    {
    //    cout << "hi"<< endl;
        for(int j = 0; j < score.size(); j++)
        {
            sum+= score[j];
        }
    }
    else
    {
        int max = teamHelper(score, team, m);
        cout << "Max is: " << max << endl;

        bool check;
        //delete element from o.g list
        auto it = std::find(score.begin(), score.end(), max);
        if(it != score.end())
        {
            score.erase(it);
            cout << "Updated array: " << endl;
            for(int j = 0; j < score.size(); j++)
            {
                cout << score[j] << " ";
            }
       
            cout << endl; 
            //bool check = sizeTeam(ateam, team);
            ateam.push_back(max);
            check = sizeTeam(ateam, team);
            if(!check)
            {
                teamFormation(score,team,m);
            }
            else
            {
                for(int i = 0; i < ateam.size(); i++)
                {
                    sum+= ateam[i];   
                }
         
            }
        }
    }
    return sum;
}

//helps to find the max
int teamHelper(vector<int> score, int team, int m)
{
   
    int p1 = 0;
    int p2 = score.size();
    long max = 0.0;
    
    //checking all elements of both subsets
    while(p1 < m && p2 > m)
    {
        if(score[p1] == score[p2])
        {
            max = score[p1];
            p2--;
        }
        else if(score[p1] > score[ p2])
        {
            max = score[p1];
            p2--;
        }
        else
        {
           max = score[p2]; 
           p1++;
        }
     }
     return max;
}






int main(int argc, const char * argv[])
{
    vector<int> score = {18,5,15,18,11,15,9,7};
    int team = 5;
    int m = 1;
    long result = teamFormation(score, team, m);
    cout << result << "\n";

    return 0;
}
