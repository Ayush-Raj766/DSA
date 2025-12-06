// #include<bits/stdc++.h>
// using namespace std;

// void genComb(int idx, vector<vector<int>>& points,
//              vector<vector<int>>& cur,
//              vector<vector<vector<int>>>& all) {
//     if(cur.size() == 4) {
//         all.push_back(cur);
//         return;
//     }
//     if(idx == points.size()) return;

//     // take
//     cur.push_back(points[idx]);
//     genComb(idx + 1, points, cur, all);
//     cur.pop_back();

//     // skip
//     genComb(idx + 1, points, cur, all);
// }

// bool checkParallel(int x1, int y1, int x2, int y2,
//                    int x3, int y3, int x4, int y4) {

//     long long dx1 = x2 - x1;
//     long long dy1 = y2 - y1;
//     long long dx2 = x4 - x3;
//     long long dy2 = y4 - y3;

//     return dy1 * dx2 == dy2 * dx1;
// }

// // Check if points A, B, C are collinear
// bool checkCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
//     return (long long)(y2 - y1) * (x3 - x1) ==
//            (long long)(y3 - y1) * (x2 - x1);
// }

// int countTrapezoids(vector<vector<int>>& points) {

//     vector<vector<vector<int>>> all;
//     vector<vector<int>> cur;
//     genComb(0, points, cur, all);
//     int count =0;
//     for(auto &c : all){
//         auto A = c[0];
//         auto B = c[1];
//         auto C = c[2];
//         auto D = c[3];

//         bool p1 = checkParallel(A[0],A[1], B[0],B[1],  C[0],C[1], D[0],D[1]);
//         bool p2 = checkParallel(A[0],A[1], C[0],C[1],  B[0],B[1], D[0],D[1]);
//         bool p3 = checkParallel(A[0],A[1], D[0],D[1],  B[0],B[1], C[0],C[1]);

//         if(p1 || p2 || p3) {
//             if(!checkCollinear(A[0],A[1], B[0],B[1], C[0],C[1]) &&
//                !checkCollinear(A[0],A[1], B[0],B[1], D[0],D[1]) &&
//                !checkCollinear(A[0],A[1], C[0],C[1], D[0],D[1]) &&
//                !checkCollinear(B[0],B[1], C[0],C[1], D[0],D[1])) {
//                 count++;
//         }
//     }
// }

//     return count;
// }

// int main() {
//     vector<vector<int>> points= {{-3,2},{3,0},{2,3},{3,2},{2,-3}};
//     // countTrapezoids( points);
//     cout<< countTrapezoids( points)<<endl;
//     return 0;
// }

class Solution
{
public
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public
    string hash(int a, int b)
    {
        int g = gcd(Math.abs(a), Math.abs(b));
        if (g == 0)
        {
            return "0/0";
        }
        int num = a / g;
        int den = b / g;
        return (num * den < 0 && den != 0 ? "-" : "") + (Math.abs(num)) + "/" + (Math.abs(den));
    }
public
    int countTrapezoids(int[][] points)
    {
        int n = points.length;
        int trapezoids = 0;
        HashMap<String, Integer> parallel_line = new HashMap<>();
        HashMap<String, Integer> collinear_line = new HashMap<>();

        for (int i = 0; i < n; i++)
        {
            int[] p2 = points[i];
            for (int j = 0; j < i; j++)
            {
                int[] p1 = points[j];

                String slope = (p1[0] != p2[0]) ? hash(p2[1] - p1[1], p2[0] - p1[0]) : "inf";

                String intercept = (p1[0] != p2[0]) ? hash((p2[1] * (p1[0] - p2[0]) - p1[1] * (p2[0] - p1[0])), (p1[0] - p2[0])) : p1[0] + "";

                String slope_key = slope;
                String full_line_key = slope + "," + intercept;

                int seen_parallel = parallel_line.getOrDefault(slope_key, 0);
                int seen_collinear = collinear_line.getOrDefault(full_line_key, 0);

                trapezoids += (seen_parallel - seen_collinear);
                parallel_line.put(slope_key, seen_parallel + 1);
                collinear_line.put(full_line_key, seen_collinear + 1);
            }
        }

        int parallelograms = 0;

        HashMap<String, Integer> parallel_lines_dist = new HashMap<>();
        HashMap<String, Integer> collinear_lines_dist = new HashMap<>();

        for(int i = 0; i < n; i++)
        {
            int[] p2 = points[i];
            for (int j = 0; j < i; j++)
            {
                int[] p1 = points[j];

                String slope = (p1[0] != p2[0]) ? hash(p2[1] - p1[1], p2[0] - p1[0]) : "inf";

                String intercept = (p1[0] != p2[0]) ? hash((p2[1] * (p1[0] - p2[0]) - p1[1] * (p2[0] - p1[0])), (p1[0] - p2[0])) : p1[0] + "";

                int dst = (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);

                String slope_dist_key = slope + "," + dst;
                String full_line_dist_key = slope + "," + intercept + "," + dst;

                int seen_parallel_dist = parallel_lines_dist.getOrDefault(slope_dist_key, 0);
                int seen_collinear_dist = collinear_lines_dist.getOrDefault(full_line_dist_key, 0);

                parallelograms += (seen_parallel_dist - seen_collinear_dist);
                parallel_lines_dist.put(slope_dist_key, seen_parallel_dist + 1);
                collinear_lines_dist.put(full_line_dist_key, seen_collinear_dist + 1);
            }
        }
        return trapezoids - parallelograms/;
    };