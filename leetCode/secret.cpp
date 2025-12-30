#include<bits/stdc++.h>
using namespace std;

class Solution{

};

int main() {
     Solution sol;

    int n = 6;
    vector<vector<int>> meetings = {
        {1, 2, 3},
        {2, 3, 7},
        {3, 4, 3},
        {4, 5, 10}
    };
    int firstPerson = 1;

    vector<int> ans = sol.findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int p : ans) {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}