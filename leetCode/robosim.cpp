#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(auto it : obstacles){
            obs.insert({it[0], it[1]});
        }
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}}; 
        for(int cmd : commands){
            if(cmd == -1){
                dir = (dir + 1) % 4;
            } else if(cmd == -2){
                dir = (dir + 3) % 4; 
            } else {
                for(int i = 0; i < cmd; i++){
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;
                    if(obs.count({newX, newY}) == 0){ 
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x*x + y*y);
                    } else {
                        break;     
                    }
                }
            }
        }
        return maxDist;
    }
};

int main() {
    Solution sol;
     vector<int> commands = {4,-1,3};
     vector<vector<int>> obstacles = {{2,4}};
    int result = sol.robotSim(commands, obstacles);
    cout << "Maximum Euclidean distance from the origin: " << result << endl;

    return 0;
}