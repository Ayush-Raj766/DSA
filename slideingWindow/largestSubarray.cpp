#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
int  lengthofLongestSubstring(string str){
    int l =0;
    int r=0;
    int n = str.length();
    int len =0;
    
    vector<int> map(256,-1);
    while(r<n){
        if(map[str[r]] !=-1){
            l = max(l , map[str[r]]+1);
        }
        map[str[r]]=r;
         len =max(len , r-l+1);
        r++;

    }
    return len;
}
};



int main() {
     string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}