#include<bits/stdc++.h>
using namespace std;

int countCollisions(string dir){
    int n = dir.size();
    int i = 0;
    int j = n - 1;
    while(i<n && dir[i] == 'L') i++;
    while(j>=0 && dir[j] == 'R') j--;
    if(i>j) return 0;
    int ans = 0;
    for(int k = i ; k <= j;k++){
        if(dir[k] != 'S'){
            ans++;
        }
    }
    return ans;
}

int main() {
    string s;
    s="RLRSLL";
    countCollisions(s);
    cout << "Number of collisions: " << countCollisions(s) << endl;
    return 0;
}