#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int gindex=0;
        int sindex=0;

        while(gindex < g.size() && sindex < s.size())
        {
            if(g[gindex] <= s[sindex]){
                gindex++;
            }
            sindex++;
        }
        
        return gindex;
    }
};

int main() {
     vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    // Create Solution object
    Solution solver;

    // Get the number of content students and print it
    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;
    return 0;
}