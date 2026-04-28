#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool dfsCheck(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]){
        vis[node] = 1 ;
        pathVis[node] = 1 ;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it , vis , pathVis , adj)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0 ;
        return false;
    }

    bool isCyclic(int v , vector<int>adj[]){
        vector<int> vis(v , 0);
        vector<int> pathvis(v , 0);
        for(int i=0 ; i<v ; i++){
            if(!vis[i]){
                if(dfsCheck(i , vis , pathvis , adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	
    return 0;
}