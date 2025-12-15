#include<bits/stdc++.h>
using namespace std;

int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto stick : sticks){
            minHeap.push(stick);
        }

         int totalCost = 0;

        while(minHeap.size()>1){
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            int res = first + second;
            totalCost+=res;
            minHeap.push(res);
        }
        return totalCost;
    }

int main() {
    vector<int> stick ={1, 8, 3, 5};
    int res = connectSticks(stick);
    cout << res;
    return 0;
}