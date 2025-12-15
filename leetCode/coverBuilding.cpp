#include<bits/stdc++.h>
using namespace std;

bool coveredbuild(set<int>& rowSet , set<int>& colset , int x , int y){
    bool left= false;
    bool right = false;
    bool up = false;
    bool down = false;

    auto it = rowSet.lower_bound(y);
    if(it != rowSet.begin()) left = true;

    it = rowSet.upper_bound(y);
    if(it != rowSet.end()) right = true;

    auto jt = colset.lower_bound(x);
    if(jt != colset.begin()) up = true;

     jt = colset.upper_bound(x);
    if(jt != colset.end()) down = true;

    return left && right && up && down;
}

int countCoveredBuildings(int n, vector<vector<int>>& buildings){
    unordered_map<int , set<int>>rowMap;
    unordered_map<int , set<int>>colMap;

    for(auto b : buildings){
        int x = b[0];
        int y = b[1];
        rowMap[x].insert(y);
        colMap[y].insert(x);
    }

    int covered = 0;

    for(auto b : buildings){
        int x = b[0];
        int y = b[1];
        
        auto &rowSet = rowMap[x];
        auto &colSet = colMap[y];
         if(coveredbuild(rowSet , colSet , x ,y)){
            covered++;
         }
    }
    return covered;
}

int main() {
    int n = 5;
    vector<vector<int>> buildings = {{1,2}, {1,4},
    {2,1}, {2,2}, {2,3}, {2,4}, {2,5},
    {3,2}, {3,3}, {3,4},
    {4,1}, {4,2}, {4,3}, {4,4}, {4,5},
    {5,2}, {5,4}};
    cout<<countCoveredBuildings(n , buildings)<<endl;
    return 0;
}