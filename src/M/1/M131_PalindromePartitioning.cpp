//
// Created by Andrii Cherniak on 3/14/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool isPalindrome(string &s, int begin, int end) {
        if (begin > end) return false;
        if (begin == end) return true;
        while (begin < end)
            if (s[begin++] != s[end--]) return false;
        return true;
    }

    void helper(string &s, int begin_id, vector<string> path, vector<vector<string> > &partitions) {
        if (begin_id == s.length()) partitions.push_back(path);
        for (int end_id = begin_id; end_id < s.length(); end_id++) {
            if (isPalindrome(s, begin_id, end_id)) {
                vector<string> path_copy = path;
                path_copy.push_back(s.substr(begin_id, end_id - begin_id + 1));
                helper(s, end_id + 1, path_copy, partitions);
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > partitions;
        if (s == "")
            return partitions;
        int L = s.length();
        vector<string> path;
        helper(s, 0, path, partitions);
        return partitions;
    }
};