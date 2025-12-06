#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> computeLPS(string pat){
        int n=pat.size();
        vector<int> lps(n,0);
        for(int i =1;i<n;i++){
            int len = lps[i-1];
            while(len>0 && pat[i] != pat[len]){
                len = lps[len-1];
            }
            if(pat[i] == pat[len]){
                len++;
            }
            lps[i]=len;
        }

        return lps;
    }

    vector<int> KMP(string text, string pattern){

        vector<int> prefix = computeLPS(pattern);

        vector<int> occurrences;
        int n=text.size();
        int m=pattern.size();
        int i=0,j=0;
        while(i<n){
            if(text[i]==pattern[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = prefix[j-1];
                }
                else{
                    i++;
                }
            }

            if(j==m){
                occurrences.push_back(i-j);
                j=prefix[j-1];
            }
        }

        return occurrences;
    }
    
};


int main() {
    string text = "ababcababcabc";
    // Define the pattern to search
    string pattern = "abc";

    // Create an object of the Solution class
    Solution sol;

    // Call the KMP function to get all match indices
    vector<int> matches = sol.KMP(text, pattern);

    // Output the results
    cout << "Pattern found at indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}