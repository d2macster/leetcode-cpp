//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>
#include <unordered_map>
#include <cmath>

using std::vector;
using std::pair;
using std::unordered_map;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int dx, dy;
        double d;
        int answer = 0;
        for (auto &p1: points) {
            unordered_map<double, int> pd(points.size());
            for (auto &p2: points) {
                if (p1 == p2) continue;
                dx = p1.first - p2.first;
                dy = p1.second - p2.second;
                d = std::sqrt(dx * dx + dy * dy);
                pd[d]++;
            }
            for (auto &p : pd)
                answer += p.second * (p.second - 1);

        }

        return answer;
    }
};