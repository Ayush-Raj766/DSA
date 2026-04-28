#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(int V , vector<int> adj[]){
        vector<int> indegree(V,0);
        vector<int> reverseAdj[V];
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                reverseAdj[it].push_back(i);
                indegree[it]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : reverseAdj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans;
    }

};

int main() {
     vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
                           {8}, {9}};
    int V = 12;  // Number of nodes in the graph

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);  // Call function to get safe nodes

    for (auto node : safeNodes) {
        cout << node << " ";  // Print the safe nodes
    }
    cout << endl;
    return 0;
}