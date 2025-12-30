#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int count = 0;
        for (int i = 0 ; i < n ; i++){
            for(int j = 1 ; j<strs.size() ; j++){
                if(strs[j-1][i] <= strs[j][i]){
                    continue;
                }
                else{
                    count++;
                    break;
                }
            }
        }
        return count;
    }

int main() {
    vector<string> strs = {"abx", "agz", "bgc", "bfc"};
    cout<<minDeletionSize(strs)<<endl;
    return 0;
}