//
// Created by Andrii Cherniak on 4/2/18.
//
#include <vector>
#include <iostream>

using namespace std;

bool sortbysecond(const pair<int, int> & p1, const pair<int, int> & p2){
    return (p1.second != p2.second)?p1.second < p2.second: p1.first < p2.first;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        int L = points.size();
        if (L <= 1) return L;
        sort(points.begin(), points.end(), sortbysecond);
        int cur_end = points[0].first - 10;
        int arrows = 0;
        for (int i = 0; i < L; i++){
            if (points[i].first > cur_end){
                arrows++;
                cur_end = points[i].second;
            }
        }
        return arrows;
    }
};