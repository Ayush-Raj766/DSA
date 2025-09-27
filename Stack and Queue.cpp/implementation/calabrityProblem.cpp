#include<bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> &m , int n){
    int top = 0;
    int down =n-1;
    while(top<down){
        if(m[top][down]==1){
            top++;
        }
        else{
            down--;
        }
    }
    int clab=top;
    for(int i =0 ; i<n;i++){
        if(i==clab) continue;
        if(m[clab][i] == 1) return -1;
        if(m[i][clab] == 0) return -1;
    }
    return clab;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int n = M.size();

    int celeb = findCelebrity(M, n);
    if (celeb == -1)
        cout << "No celebrity found\n";
    else
        cout << "Celebrity is person index: " << celeb << "\n"; // 0-based index
    return 0;
}