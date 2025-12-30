#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        vector<int> vis(V,0);
        
        stack<int>st;
         vector<int> dfs;
         st.push(0);
    vis[0] = 1;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            dfs.push_back(node);


            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] =1;
                    st.push(it);
                }
            }
        }
        return dfs;
    }
};

void addEdge(vector<int> adj[] , int u ,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 2); 
    // addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);
    return 0;
}