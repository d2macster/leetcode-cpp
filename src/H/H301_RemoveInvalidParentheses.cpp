//
// Created by Andrii Cherniak on 5/29/18.
//
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    bool isValid(string &s) {
        int check = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') check++;
            else if (s[i] == ')') {
                check--;
                if (check < 0) return false;
            }
        }
        return (check == 0);
    }

    void removeK(string &s, int pos, int k, unordered_set<string> &result) {
        if (k == 0) {
            if (isValid(s)) {
                string ss = "";
                for (char c: s) if (c != (char) 0) ss += c;
                result.insert(ss);
            }
            return;
        }
        int L = s.size();
        if (pos >= L && k > 0) return;
        for (int i = pos; i < L; i++) {
            if (s[i] == ')' || s[i] == '(') {
                char c = s[i];
                s[i] = (char) 0;
                removeK(s, i + 1, k - 1, result);
                s[i] = c;
            }
        }
        return;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int P = 0;
        for (char c: s) P += (c == ')' || c == '(');
        unordered_set<string> rs;
        if (P == 0) {
            result.push_back(s);
            return result;
        }
        for (int p = 0; p <= P; p++) {
            removeK(s, 0, p, rs);
            if (!rs.empty()) {
                for (string rss: rs) result.push_back(rss);
                return result;
            }
        }
        result.push_back(s);
        return result;
    }
};