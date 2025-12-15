#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr) {
        priority_queue<int , vector<int> , greater<int>> minHeap;
        vector<int> res(arr.size());
        for (int x : arr) {
            minHeap.push(x);
        }
        unordered_map<int, int> rankMap;
        int rank = 1;
        while (!minHeap.empty()) {
            int x = minHeap.top();
            minHeap.pop();
            if (rankMap.find(x) == rankMap.end()) {
                rankMap[x] = rank++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            res[i] = rankMap[arr[i]];
        }
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {20, 15, 26, 2, 98, 6};

    vector<int> res = obj.replaceWithRank(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}