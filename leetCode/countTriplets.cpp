#include<bits/stdc++.h>
using namespace std;



int countTriples(int n){
    int count = 0;

    for(int a = 1 ; a<=n ; a++){
        for(int b = 1 ; b<=n ; b++){
            int c2 = a*a + b*b;
            int c = sqrt(c2);

            if(c<=n && c2 == c*c){
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n = 10;
    cout<< countTriples(n)<<endl;
    return 0;
}