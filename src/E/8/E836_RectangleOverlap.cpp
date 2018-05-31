//
// Created by Andrii Cherniak on 5/31/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        int x1l = rec1[0];
        int y1l = rec1[1];
        int x1r = rec1[2];
        int y1r = rec1[3];

        int x2l = rec2[0];
        int y2l = rec2[1];
        int x2r = rec2[2];
        int y2r = rec2[3];

        if (x1r <= x2l) return false;
        if (x2r <= x1l) return false;
        if (y1l >= y2r) return false;
        if (y1r <= y2l) return false;

        return true;
    }
};