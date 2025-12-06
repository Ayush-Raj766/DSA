#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeZFunction(const string& s) {
        int n=s.size();
        vector<int> Z(n,0);
        int l=0, r=0;
        for(int i=1;i<n;i++){
            if(i<=r){
                Z[i]=min(r-i+1,Z[i-l]);
            }
            while(i+Z[i]<n && s[Z[i]]==s[i+Z[i]]){
                Z[i]++;
            }
            if(i+Z[i]-1>r){
                l=i;
                r=i+Z[i]-1;
            }
        }
        return Z;
    }

    vector<int> zFunctionSearch(const string& text, const string& pattern) {
        string combined = pattern + "$" + text;
        vector<int> Z = computeZFunction(combined);
        vector<int> occurrences;
        int pLen = pattern.size();
        for (int i = 0; i < Z.size(); i++) {
            if (Z[i] == pLen) {
                occurrences.push_back(i - pLen - 1);
            }
        }
        return occurrences;
    }
};
int main() {
    string text = "ababcababc";
    string pattern = "ab";

    Solution sol;
    vector<int> indices = sol.zFunctionSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}