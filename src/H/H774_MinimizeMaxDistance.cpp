//
// Created by Andrii Cherniak on 4/19/18.
//
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
    bool minmax(vector<double> &D, int K, double targetD) {
        for (double d: D) {
            K -= int(ceil(d / targetD)) - 1;
            if (K < 0) return false;
        }
        return true;
    }

public:
    double minmaxGasDist(vector<int> &stations, int K) {
        int L = stations.size();
        vector<double> D = vector<double>(L - 1, 0);
        for (int i = 0; i < L - 1; i++) D[i] = double(stations[i + 1] - stations[i]);
        sort(D.begin(), D.end());
        reverse(D.begin(), D.end());
        double upper = *D.begin(), lower = 0.0, prev = 0.0;

        while (fabs(prev - (lower + upper) / 2) > 1e-6) {
            double mid = (lower + upper) / 2;
            bool decision = minmax(D, K, mid);
            if (decision) upper = mid;
            else lower = mid;
            prev = mid;

        }

        return (lower + upper) / 2;
    }
};