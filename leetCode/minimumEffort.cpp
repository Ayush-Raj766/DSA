#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(vector<int> &a , vector<int> &b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin() , tasks.end() , compare);

        int currentTime = 0;
        int totalEffort = 0;

        for(auto &task : tasks){
            int actual = task[0];
            int minimum = task[1];

            if(currentTime < minimum){
                int effortNeeded = minimum - currentTime;
                totalEffort += effortNeeded;
                currentTime += effortNeeded;
            }
            currentTime -= actual;
        }
        return totalEffort;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> tasks = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};
    int result = obj.minimumEffort(tasks);
    cout << "Minimum Effort Required: " << result << endl;
    return 0;
}