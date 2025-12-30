#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool isValid(string s){
        int maxopen = 0 ;
        int minopen = 0 ;

        for(char c : s){
            if(c == '('){
                minopen++;
                maxopen++;
            }
            else if(c ==')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }

            if(maxopen < 0){
                return false;
            }
            minopen = max(minopen , 0);
        }
        return minopen == 0;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    if (sol.isValid(s)) {
        cout << "Valid parenthesis string" << endl;
    } else {
        cout << "Invalid parenthesis string" << endl;
    }

    return 0;
}