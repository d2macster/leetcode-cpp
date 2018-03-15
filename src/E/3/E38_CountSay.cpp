//
// Created by Andrii Cherniak on 3/15/18.
//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
    void naming(vector<int> &output, int digit, int cnt) {
        vector<int> number = vector<int>();
        while (cnt > 0) {
            number.push_back(cnt % 10);
            cnt /= 10;
        }
        reverse(number.begin(), number.end());
        for (int n: number) output.push_back(n);
        output.push_back(digit);
    }

    vector<int> iterate(vector<int> counter) {
        vector<int> new_counter;
        int L = counter.size();
        int prev = counter[0];
        int cnt = 1;
        for (int i = 1; i < L; i++) {
            if (prev == counter[i]) cnt++;
            else {
                naming(new_counter, prev, cnt);
                prev = counter[i];
                cnt = 1;
            }
        }
        naming(new_counter, prev, cnt);
        return new_counter;
    }

public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        vector<int> counter = vector<int>(1, 1);
        for (int i = 2; i <= n; i++) {
            counter = iterate(counter);
        }
        ostringstream oss;
        for (int v : counter) oss << v;
        return oss.str();

    }
};