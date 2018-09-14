#include <iostream>
#include <algorithm> //for heap operations
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    //initialize a vector
    vector<int> v1 = {20, 30, 40, 25, 15};

    //convert vector into a heap
    //using make_heap()
    make_heap(v1.begin(), v1.end());

    //displaying the maximum element of heap 
    //using front()
    cout << "The maximum element on the heap is: " ;
    cout << v1.front() << endl;

    //using push_back() to enter element in vector
    v1.push_back(50);

    //using push_heap() to reorder elements
    push_heap(v1.begin(), v1.end());

    //Displaying the maximum element of heap 
    //using front()
    cout << "The maximum element of heap after psuh is: " ;
    cout << v1.front() << endl;

    //using pop_heap() to delete the maximum element
    pop_heap(v1.begin(), v1.end());

    //pop_back removes the last element in the vector
    v1.pop_back();

    //Displaying the maximum element of the heap
    //using front()
    cout << "The maximum element of heap after pop is: ";
    cout << v1.front() << endl;

    return 0;
}
