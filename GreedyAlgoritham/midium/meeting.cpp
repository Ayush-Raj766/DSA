#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
     vector<int> maxMeetings(vector<int>& start, vector<int>& end){
        vector<tuple<int ,int ,int>> meetings;
        for(int i = 0 ; i<end.size() ; i++){
            meetings.push_back({end[i]  ,start[i] ,  i+1});
        }

        sort(meetings.begin() , meetings.end());

        int lastEnd= -1;

        vector<int> result;

        for(auto meeting : meetings){
            int e = get<0>(meeting);
            int s = get<1>(meeting);
            int idx = get<2>(meeting);

            if(s > lastEnd){
                result.push_back(idx);
                lastEnd = e;
            }

        }
        return result;
     }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);

    for (int idx : res) cout << idx << " ";
    return 0;
}