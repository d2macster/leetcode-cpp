//
// Created by Andrii Cherniak on 6/21/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    void helper(string &num, int target, int pos, vector<string> &result, string path, long eval, long prev) {
        int L = num.size();
        if (pos == L) {
            if (target == eval) result.push_back(path);
            return;
        }
        long cur_v = 0;
        string s = "";
        for (int i = pos; i < L; i++) {
            if (num[pos] == '0' && i > pos) break;
            s += num[i];
            cur_v = 10 * cur_v + num[i] - '0';
            if (pos == 0) helper(num, target, i + 1, result, s, cur_v, cur_v);
            else {
                helper(num, target, i + 1, result, path + "+" + s, eval + cur_v, cur_v);
                helper(num, target, i + 1, result, path + "-" + s, eval - cur_v, -cur_v);
                helper(num, target, i + 1, result, path + "*" + s, eval - prev + prev * cur_v, prev * cur_v);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;

        helper(num, target, 0, result, "", 0, 0);

        return result;
    }
};