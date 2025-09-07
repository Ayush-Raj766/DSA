#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;
    if(s1.length() != s2.length()) {
        cout<<"Strings are not isomerphic"<<endl;
        return 0;
    }
    unordered_map<char, char> m1;
    for(int i = 0; i < s1.length(); i++) {
        if(m1.find(s1[i]) == m1.end()) {
            m1[s1[i]] = s2[i];
        } else if(m1[s1[i]] != s2[i]) {
            cout<<"Strings are not isomerphic"<<endl;
            return 0;
        }
        
    }
    cout<<"Strings are isomerphic"<<endl;
    return 0;
}