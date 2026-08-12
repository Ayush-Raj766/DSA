#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

void dfs(int node , vector<int> adj[] , vector<int> &vis , stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

public:

int kosaraju(int v , vector<int> adj[]){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i = 0 ; i < v ; i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    vector<int> transpose[v];
    for(int i = 0 ; i < v ; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }

    int count = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            count++;
            dfs(node,transpose,vis,st);
        }
    }
    return count;
}

};

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}