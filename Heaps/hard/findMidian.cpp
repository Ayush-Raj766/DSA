#include<bits/stdc++.h>
using namespace std;

class MedianFinder{
    public:

    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int>maxheap;

    
    MedianFinder(){

    }

    void addNum(int n ){
        maxheap.push(n);
        minheap.push(maxheap.top());
        maxheap.pop();

        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian(){

        if(minheap.size() == maxheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        return maxheap.top();
    }

};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // Output: 2
    return 0;
}
