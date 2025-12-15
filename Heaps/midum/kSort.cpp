#include<bits/stdc++.h>
using namespace std;

vector<int> ksort(vector<int> &nums , int k){
    priority_queue<int , vector<int> , greater<int>> minHeap;
    vector<int> result;
    int n = nums.size();
    for(int num : nums){
        minHeap.push(num);
        if(minHeap.size() > k){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int>nums={6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> result = ksort(nums , k);
    for(int val : result){
        cout << val << " ";
    }
    
    return 0;
}