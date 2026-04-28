#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int minimumMultiplications(vector<int>& arr ,  int start , int end){
        int mod = 100000;
        vector<int> dist(mod , 1e9);
        dist[start] = 0;
        queue<pair<int,int>> q;
        q.push({0,start});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second;
            for(auto &it : arr){
                int newNode = (node * it) %mod;
                if(steps + 1 < dist[newNode]){
                    dist[newNode] = steps + 1;
                    if(newNode == end) return steps + 1;
                    q.push({steps + 1, newNode});
                }

            }

        }
        return -1;
    }
};

int main() {
     int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;
    return 0;
}