//
// Created by Andrii Cherniak on 3/22/18.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> pairs = vector<string>(n, "");
        for (int i = 1; i <= n; i++) pairs[i-1] = to_string(i);
//        for (string & p: pairs) cout << p << " ";
//        cout << endl;
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                pairs[i] = "(" + pairs[i] + "," + pairs[n - 1 - i] + ")";
            }
            n /= 2;
        }
//        for (string & p: pairs) cout << p << " ";
//        cout << endl;
        return pairs[0];
    }
};