#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the string: ";
    getline(cin , s);

    int l = 0;
    bool start = false;
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i]) || s[i] == '-' || s[i] == '+') {
            if(!start) {
                l = i;
                start = true;
            }
            count++;  // count the current character
        }
        else {
            if(start) break; // stop when number ends
        }
    }

    s = s.substr(l, count);
    cout<<"Integer value: "<<s<<endl;
    return 0;
}
