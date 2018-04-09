//
// Created by Andrii Cherniak on 4/9/18.
//

#include <vector>
#include <unordered_map>
#include <limits>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

public:
    int maxPoints(vector<Point> &points) {
        int L = points.size();
        if (L <= 2) return L;
        int N = 0;
        for (int i = 0; i < L; i++) {
            unordered_map<string, int> slopes;
            int duplicates = 0;
            for (int j = 0; j < L; j++) {
                long dx = points[j].x - points[i].x;
                long dy = points[j].y - points[i].y;
                if (dx == 0 && dy == 0)duplicates++;
                else {
                    long g = gcd(dx, dy);
                    string slope = (dx == 0) ? to_string(INT_MAX) : to_string(dy / g) + ":" + to_string(dx / g);
                    slopes[slope]++;
                }
            }
            N = max(N, duplicates);
            for (auto it: slopes) {
                N = max(N, duplicates + it.second);
            }
        }
        return N;
    }
};