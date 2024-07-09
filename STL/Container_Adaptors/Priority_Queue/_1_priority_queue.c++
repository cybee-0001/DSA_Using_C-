#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Max Heap
    priority_queue<int> maxHeap;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(0);
    int n = maxHeap.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(0);
    int m = minHeap.size();
    for (int i = 0; i < m; i++)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    cout<<"Is Empty or not : "<<minHeap.empty()<<endl;
}
