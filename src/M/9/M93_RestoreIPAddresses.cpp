//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Solution {
    void helper(string &s, int s_id, vector<int> &path, int segment, vector<string> &ips) {
        if (s_id == s.length() && segment == 4) {

            ips.push_back(to_string(path[0]) + "." +
                          to_string(path[1]) + "." +
                          to_string(path[2]) + "." +
                          to_string(path[3]));

        } else if (s_id == s.length() || segment == 4) return;
        for (int len = 1; len <= 3, s_id + len <= s.length(); len++){
            if (len >= 2 && s[s_id] == '0') return;
            int v = 0;
            for (int i = s_id; i < s_id + len; i++) v = v * 10 + (s[i] - '0');
            if (v > 255) return;
            path[segment] = v;
            helper(s, s_id + len, path, segment+1, ips);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        int L = s.length();
        vector<int> path = vector<int>(4, 0);
        helper(s, 0, path, 0, ips);
        return ips;
    }
};