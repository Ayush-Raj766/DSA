#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the roman numeral: ";
    cin>>s;
    int result = 0;
    map<char , int>m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;    
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    for(int i = 0 ; i < s.length() ; i++){
        if(i+1 < s.length() && m[s[i]] < m[s[i+1]]){
            result -= m[s[i]];
        }
        else{
            result += m[s[i]];
        }
    }
    cout<<"Integer value: "<<result<<endl;
    return 0;
}