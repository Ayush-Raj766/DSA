#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReversalsToBalance(const string& expression) {
        int openBracket = 0 ;
        int closeBracket = 0 ;

        for(char ch : expression){
            if(ch == '('){
                openBracket++;

            }
            else{
                if(openBracket > 0){
                    openBracket--;
                }
                else{
                    closeBracket++;
                }
            }
        }
        if((openBracket + closeBracket) % 2 != 0){
            return -1;
        }
        return (openBracket + 1) / 2 + (closeBracket + 1) / 2;
    }
};
int main() {
     string expression = "(()))(";

    // Create object of Solution
    Solution solver;

    // Get result from function
    int result = solver.minReversalsToBalance(expression);

    // Print the result
    cout << "Minimum reversals required: " << result << endl;

    
    return 0;
}