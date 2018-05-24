//
// Created by Andrii Cherniak on 5/23/18.
//
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int L = points.size();
        if (L < 2)
            return false;
        if (L == 2)
            return true;
        int dx1, dy1, dx2, dy2;
        bool pos = false;
        bool neg = false;

        for(int i = 0; i < L; i++){
            dx1 = points[(i+1) % L][0] - points[i][0];
            dy1 = points[(i+1) % L][1] - points[i][1];

            dx2 = points[(i+2) % L][0] - points[i][0];
            dy2 = points[(i+2) % L][1] - points[i][1];

            int p = dx1*dy2 - dy1*dx2;
            if (p > 0){
                pos = true;
                if (neg) return false;
            }
            if (p < 0){
                neg = true;
                if(pos) return false;
            }

        }
        return true;
    }
};