//
// Created by Andrii Cherniak on 3/13/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<vector<char> > m = vector<vector<char> >(10, vector<char>());

    void helper(vector<string> &combinations, string &digits, int d_id, string prefix) {
        if (d_id >= digits.length()) {
            combinations.push_back(prefix);
            return;
        }
        int d = digits[d_id] - '0';
        for (char ch: m[d]) {
            helper(combinations, digits, d_id + 1, prefix + ch);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits == "")
            return combinations;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};

        helper(combinations, digits, 0, "");

        return combinations;
    }
};