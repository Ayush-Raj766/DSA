#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int leastInterval(vector<char> &tasks , int n){
        unordered_map<char , int> freq;
        for(char ch : tasks){
            freq[ch]++;
        }

        priority_queue<int , vector<int> , less<int>> maxheap;

        for(auto& enter : freq ){
            maxheap.push(enter.second);
        }
        int maxtime = maxheap.top();
        int freqMax = 0;
         while(!maxheap.empty() && maxheap.top() == maxtime){
            freqMax++;
            maxheap.pop();
        }

        int totaltask = tasks.size();
        int partition = (maxtime-1)*(n+1) + freqMax;

        return max(partition , totaltask);

    }
};

int main() {
    Solution obj;

    // Input task list
    vector<char> tasks = {'A','A','A','B','B','B'};

    // Cooldown period
    int n = 2;

    // Output the least interval required to finish all tasks
    cout << obj.leastInterval(tasks, n) << endl;

    return 0;
}