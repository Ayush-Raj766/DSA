#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the string: ";
    getline(cin , s);

    reverse(s.begin() , s.end());

    int l = 0;

    for(int i = 0 ; i<=s.length() ;i++){
        if(s[i]==' ' || i==s.length()){
            reverse(s.begin()+l , s.begin()+i);
            l = i+1;
        }
        
    }
    cout << "Resultant string: " << s << endl;
    return 0;
}