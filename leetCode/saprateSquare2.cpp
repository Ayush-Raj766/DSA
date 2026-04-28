#include <bits/stdc++.h>
using namespace std;

double areaBelow(vector<vector<int>> &square, double k)
{
    double area = 0.0;
    vector<pair<double, double>> intervals;
    double height = 0.0;
    for (auto &sq : square){
        double x = sq[0];
        double side = sq[2];
        double bottom = sq[1];
        double top = sq[1] + side;
        if (k <= bottom)
        {
            continue;
        }
        double h = min(k, top) - bottom;
        if(h <=0) continue;
        height = h;
        intervals.push_back({x, x + side});

    }

    sort(intervals.begin(), intervals.end());
     
    double start = intervals[0].first;;
    double end = intervals[0].second;

    for(int i =1;i<intervals.size();i++){
        if(intervals[i].first <= end){
            end = max(end , intervals[i].second);
        }else{
            area += (end - start)* height;
            start = intervals[i].first;
            end = intervals[i].second;
        }
    }

    area += (end - start)* height;

    return area;
}
double separateSquares(vector<vector<int>> &square)
{
    double totalArea = 0.0;
    double low, high;
    for (const auto &sq : square)
    {
        double sideLength = sq[2];
        totalArea += sideLength * sideLength;
        low = min(low, (double)sq[1]);
        high = max(high, (double)(sq[1] + sideLength));
    }
    int target = totalArea / 2.0;
    while (high - low > 1e-6)
    {
        double mid = (low + high) / 2.0;
        if (areaBelow(square, mid) < target)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> square = {{0, 0, 1},
                                  {3, 3, 1},
                                  {4, 4, 1},
                                  {4, 3, 1}};

    cout << separateSquares(square) << endl;

    return 0;
}