#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> gq)
{
    stack <int> g = gq;
    while(!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';


}


int main()
{
    stack <int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

 //   cout << "The stack gquiz is : ";
 //   showstack(gquiz);

//    cout << "\n gquiz.size(): " << gquiz.size();
//    cout << "\n gquiz.top(): " << gquiz.top();

//    cout << "\n gquiz.pop() : " ;
//    gquiz.pop();
    showstack(gquiz);


    return 0;
}
