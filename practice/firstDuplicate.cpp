#include <iostream>
#include <vector>
#include <map>
#include <iterator>


int firstDuplicate(std::vector<int> a)
{
    std::map <int, int> mymap;
    int count = 0;
    for(std::size_t i = 0; i < a.size(); ++i)
    {
        if(mymap.find(a[i]) == mymap.end())
        {
            //not found so set key to arbitrary value
            mymap.insert(std::pair <int, int> (a[i], -2));
        }
        else
        {
            count++;
            //found
            if(count < 2)
            {
                mymap.at(a[i]) = i;
            }
            //std::cout<<"count: " << count<< std::endl;
        }
    }

    std::map<int, int>::iterator pos;
    int min = 10000;
    int expectedVal = -1;
    //iterate through hashtable to find the minimal index
    for(pos = mymap.begin(); pos != mymap.end(); ++pos)
    {
        std::cout<<"( "<< pos->first << "," << pos->second<< " )" <<std::endl;
        if(pos->second < min && pos->second != -2)
        {
            min = pos->second;
            expectedVal = pos->first;
        }
   }
   return expectedVal;
}

int main(int argc, const char * argv[])
{
    std::vector<int> a = {1,1,2,2,1};
    int x = firstDuplicate(a);
    std::cout << x << std::endl;
    return 0;
}
