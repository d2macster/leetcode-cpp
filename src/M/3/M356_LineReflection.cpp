//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>> &points) {

        unordered_map<int, set<int> > groups;
        for (pair<int, int> p: points)
            groups[p.second].insert(p.first);

        vector<double> y_axis;

        for (auto it: groups) {
            set<int> xx = it.second;
            int Lx = xx.size();
            double mean = 0;
            for (int x: xx)
                mean += x;
            mean /= Lx;
            set<int >::iterator it_l = xx.begin();
            set<int >::iterator it_r = xx.end();
            it_r--;

            while (*it_l < *it_r){
                if (abs(*it_l - mean) != abs(*it_r - mean)) return false;
                it_l++;
                it_r--;
            }
            if (!y_axis.empty() && y_axis[y_axis.size() - 1] != mean)
                return false;
            y_axis.push_back(mean);
        }
        return true;
    }
};