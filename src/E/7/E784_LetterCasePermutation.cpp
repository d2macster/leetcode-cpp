//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    void helper(string &S, int s_id, string path, vector<string> &permutations) {
        if (s_id == S.length()) {
            permutations.push_back(path);
            return;
        }
        char ch = S[s_id];
        helper(S, s_id + 1, path + ch, permutations);
        if (!isdigit(ch)) {
            if (isupper(ch)) {
                ch = tolower(ch);
                helper(S, s_id + 1, path + ch, permutations);
            }
            else {
                ch = toupper(ch);
                helper(S, s_id + 1, path + ch, permutations);
            }
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        vector<string> permutations;
        helper(S, 0, "", permutations);
        return permutations;
    }
};