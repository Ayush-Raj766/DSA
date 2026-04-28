#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis) {
        vis[node] = 1;
        dfsvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (checkCycle(it, adj, vis, dfsvis)) {
                    return true;
                }
            }
            else if (dfsvis[it]) {  // FIXED
                return true;
            }
        }

        dfsvis[node] = 0;
        return false;
    }

    void topoDFS(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                topoDFS(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        // Step 1: Cycle check
        vector<int> vis(numCourses, 0), dfsvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (checkCycle(i, adj, vis, dfsvis)) {
                    return {};
                }
            }
        }

        // Step 2: Topological Sort
        vector<int> vis2(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis2[i]) {
                topoDFS(i, adj, vis2, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;

    vector<int> ans = sol.findOrder(numCourses, prerequisites);

    for (int x : ans) cout << x << " ";
    return 0;
}