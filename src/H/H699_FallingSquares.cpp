//
// Created by Andrii Cherniak on 4/23/18.
//
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>> &positions) {
        vector<int> height;
        set<int> coords;
        int x = 0;
        for (pair<int, int> p: positions) {
            coords.insert(p.first);
            coords.insert(p.first + p.second - 1);
        }
        unordered_map<int, int> coordinate_mapper;
        for (int c: coords) coordinate_mapper[c] = x++;
        vector<int> h = vector<int>(x, 0);
        int curMax = 0;
        for (pair<int, int> p: positions) {
            int x1 = coordinate_mapper[p.first];
            int x2 = coordinate_mapper[p.first + p.second - 1];
            int maxH = 0;
            for (int x = x1; x <= x2; x++) maxH = max(maxH, h[x]);
            maxH += p.second;
            for (int x = x1; x <= x2; x++) h[x] = maxH;
            curMax = max(curMax, maxH);
            height.push_back(curMax);
        }

        return height;
    }
};