#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the string: ";
    cin>>s;
    map<char ,int>m;
    for(int x:s){
        m[x]++;
    }

    vector<pair<char,int>>v;
    for(auto x:m){
        v.push_back(x);
    }
    sort(v.begin(),v.end(),[](pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    });
    for(auto x:v){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}





// [](pair<char,int>&a,pair<char,int>&b){
//         return a.second>b.second;


// self comparetor


// bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
//     return a.second < b.second; // ascending order by value
// }