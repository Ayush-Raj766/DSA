#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countPlatforms(int n , int arr[] , int dep[]){
        sort(arr ,  arr+n);
        sort(dep , dep + n);

        int platform = 1 ;
        int i = 1 ;  
        int j = 0 ;
        int result = 1;

        while(i <n && j < n){
            if(arr[i] <= dep[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }

            result = max(result , platform);

        }
        return result;
    }
};

int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    cout << "Minimum number of Platforms required " 
         << obj.countPlatforms(n, arr, dep) << endl;
    return 0;
}