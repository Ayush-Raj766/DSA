#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isNStraightHand(vector<int> &hand , int gs){
        if(hand.size() % gs != 0) return false;
        map <int , int>freq;
        for(auto hand : hand){
            freq[hand]++;
        }
        
        auto it = freq.begin();
        while(it != freq.end()){

            if(it->second == 0){
                ++it;
                continue;
            }

            int start = it->first;
            int count = it->second;

            for(int i=0; i<gs ; i++){
                if(freq[i+start] < count) return false;

                 freq[start + i] -= count;
            }

            ++it;

        }

        return true;
        
    }
};

int main() {
     Solution sol;

    // Test case 1
    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1 = 3;
    cout << sol.isNStraightHand(hand1, groupSize1) << endl;  
    // Output: 1 (true)

    // Test case 2
    vector<int> hand2 = {1,2,3,4,5};
    int groupSize2 = 4;
    cout << sol.isNStraightHand(hand2, groupSize2) << endl; 
    return 0;
}