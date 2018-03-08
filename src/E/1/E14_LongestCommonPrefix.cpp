//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int L = strs.size();
        if (L == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < L; i++) {
            int l = std::min(prefix.length(), strs[i].length());
            int j = 0;
            for (; j < l && prefix[j] == strs[i][j]; j++) {}
            if (!j) return "";
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};