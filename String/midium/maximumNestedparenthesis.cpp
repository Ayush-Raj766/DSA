#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the string: ";
    cin>>s;
    int depth =0;
    int res =0;
    for (int i=0; i<s.length();i++){
        if(s[i] == '('){
            depth++;
            

        }
        else if(s[i] ==')'){
            depth--;
        }
        res = max(res , depth);
    }
    cout<<"maximum depth is "<<res;
    return 0;
}