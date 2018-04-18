//
// Created by Andrii Cherniak on 4/18/18.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int Ls = s.size();
        int Lt = t.size();
        if (Lt > Ls || Ls == 0 || Lt == 0) return "";
        int left = 0;
        int right = 0;
        vector<int> t_counter = vector<int>(255, 0);
        vector<int> s_counter = vector<int>(255, 0);

        unordered_set<int> not_matched;

        for (char c: t) {
            t_counter[int(c)]++;
            not_matched.insert(int(c));
        }

        int best_left = 0;
        int best_right = Ls;

        for (int right = 0; right < Ls; right++) {
            int c = int(s[right]);
            s_counter[c]++;
            if (s_counter[c] >= t_counter[c]) not_matched.erase(c);

            while (left <= right && not_matched.empty()){
                if (right - left < best_right - best_left) {
                    best_left = left;
                    best_right = right;
                }
                int c = int(s[left]);
                s_counter[c]--;
                if (s_counter[c] < t_counter[c]) not_matched.insert(c);
                left++;
            }
        }

        return (best_right < Ls) ? s.substr(best_left, best_right - best_left + 1) : "";
    }
};