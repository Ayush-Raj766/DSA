#include <bits/stdc++.h>
using namespace std;


static const long long MOD = 1e9 + 7;
   int maxCommon(set<int> &hDiff, set<int> &vDiff)
{
    int maxSide = 0;
    for (const auto &h : hDiff)
    {
        if (vDiff.find(h) != vDiff.end())
        {
            maxSide = max(maxSide, h);
        }
    }

    return maxSide;
}

set<int> diff(vector<int> &fences)
{
    set<int> res;
    for(int i = 0 ; i<fences.size() -1 ; i++){
        for(int j = i +1 ; j<fences.size(); j++){
            res.insert(fences[j] - fences[i]);
        }
    }

    return res;
}

int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
{

   hFences.push_back(1);
   hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    set<int> hDiff = diff(hFences);
    set<int> vDiff = diff(vFences);

    int maxSide = maxCommon(hDiff, vDiff);

if (maxSide == 0)
        return -1;

    long long area = (1LL * maxSide * maxSide) % MOD;
    return area;
};
int main()
{
    int m = 5;
    int n = 6;

    vector<int> hFences = {2, 4};
     vector<int> vFences = {2, 3} ;

     cout<< maximizeSquareArea(m, n, hFences, vFences)<<endl;
     return 0;
}