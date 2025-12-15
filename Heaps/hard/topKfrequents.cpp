#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int , int> mp;
        priority_queue<pair<int , int>>pq;
        vector<int>res;
        for(auto nums : nums){
            mp[nums]++;
        }

        for(auto &it : mp ){
            pq.push({it.second , it.first});
        }
        int i = 0;
        while(!pq.empty() &&  i < k){
            res.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return res;
    }

int main() {
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    topKFrequent(nums , k);

    vector<int> ans = topKFrequent(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}