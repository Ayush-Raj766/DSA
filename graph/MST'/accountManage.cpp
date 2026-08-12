#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent , rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1 , 0);

        for(int i = 0 ; i < n+1 ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    int unionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return 0;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return 1;
    }
};

class Solution{
    public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n  =  accounts.size();
        
        DSU dsu(n);
        unordered_map<string , int> mp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    dsu.unionByRank(i , mp[mail]);
                }

            }

        }
        vector<string> mergedMail[n];
        for(auto it : mp){
            
            string mail = it.first;
            int node = it.second;
            int par = dsu.findUPar(node);
            mergedMail[par].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++){
            if(mergedMail[i].size() == 0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMail[i].begin() , mergedMail[i].end());
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }

};

int main() {
     vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    // Create Solution object
    Solution obj;

    // Call function
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    // Print output
    for (auto &acc : ans) {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}