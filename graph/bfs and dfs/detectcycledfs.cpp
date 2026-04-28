#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    bool detect(int s , int v , vector<int> adj[] , vector<int>& vis){
        stack<pair<int, int>> st;
        st.push({s,-1});
        vis[s]= 1 ;
        while(!st.empty()){
            int node = st.top().first;
            int parent = st.top().second;
            st.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    st.push({it , node});
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
     vector<int> adj[4] = {{1, 2},    // 0
    {0, 3},    // 1
    {0, 3},    // 2
    {1, 2}     // 3
};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}