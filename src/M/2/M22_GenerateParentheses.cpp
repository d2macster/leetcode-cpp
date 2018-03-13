//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    void helper(string prefix, int open, int close, vector<string> &result) {
        if (!open && !close) {
            result.push_back(prefix);
            return;
        }
        if (open) helper(prefix + "(", open - 1, close + 1, result);
        if (close) helper(prefix + ")", open, close - 1, result);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) return result;
        helper("", n, 0, result);
        return result;
    }
};