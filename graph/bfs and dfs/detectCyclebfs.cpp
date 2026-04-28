#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    bool detect(int s , int v , vector<int> adj[] , vector<int>& vis){
        queue<pair<int, int>> q;
        q.push({s,-1});
        vis[s]= 1 ;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it , node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V , vector<int> adj[]){
        vector<int> vis (V , 0);
        for(int i =0 ; i<V ; i++){
            if(!vis[i]){
                if(detect(i , V , adj , vis)){
                    return true;
                }
            }

        }
        return false;
    }
};

int main() {
     vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}