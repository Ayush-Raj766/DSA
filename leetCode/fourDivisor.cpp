#include<bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int>& nums) {
    int res = 0;

    for(int num :nums){
        int count =0 ;
        int sum = 0 ;

        for(int i = 1 ; i*i <= num ; i++){
            if(num % i == 0 ){
                count++;
                sum+= i;

                if(i != num/i){
                    count++;
                    sum+= num/i;
                }
            }
            if(count > 4){
                break;
            }
        }

        if(count == 4){
            res += sum;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {21 , 21 , 5 , 9};
    cout<<sumFourDivisors(nums)<<endl;
    return 0;
}