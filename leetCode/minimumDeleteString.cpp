#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int n = s.size();
    int deletion = 0;
    int bcount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            bcount++;
        }   
        if(s[i] == 'a') {
            deletion = min(deletion + 1, bcount);
        }

    }
    return deletion;
}
int main() {
    string s = "aabaabbbaabbbbbbbbbbab";
    cout << minimumDeletions(s) << endl;
    return 0;
}