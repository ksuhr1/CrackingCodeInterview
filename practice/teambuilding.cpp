#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int teamHelper(vector<int> score, int team, int m);

long teamFormation(vector<int> score, int team, int m)
{
    vector<int> ateam;
    int max = teamHelper(score, team, m);
    cout << "Max is: " << max << endl;


     //delete element from o.g list
      auto it = std::find(score.begin(), score.end(), max);
      if(it != score.end())
      {
          score.erase(it);
       //   teamFormation(score,team,m);
    
      }
 
    //update score array, remove max elements
    cout << "Updated array: " << endl;
    for(int j = 0; j < score.size(); j++)
    {
        cout << score[j] << " ";
    }
       
    cout << endl;

    if(ateam.size() < team)
    {
        teamSum(ateam, max);       
 //       ateam.push_back(max);
      //  teamFormation(score, team, m);
     /*   for(int n = 0; n < ateam.size(); n++)
        {
            cout << ateam[n] << " " ;
        }
     */   cout << endl;
    }
    return 5;
}

long teamSum(vector<int> ateam, int max)
{
    ateam.push_back(max);
    for(int n = 0; n < ateam.size(); n++)
    }
        cout << ateam[n] << " ";
    }
    cout << endl;

}


//helps to find the max
int teamHelper(vector<int> score, int team, int m)
{
   
    int p1 = 0;
    int p2 = score.size();
    long max = 0.0;

    while(p1 < m && p2 > m)
    {
        if(score[p1] > score[ p2])
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
    vector<int> score = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int team = 3;
    int m = 4;
    long result = teamFormation(score, team, m);
    cout << result << "\n";

    return 0;
}
