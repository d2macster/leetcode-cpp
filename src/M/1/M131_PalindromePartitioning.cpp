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

    void helper(string &s, int begin_id, vector<string> &path, int path_id, vector<vector<string> > &partitions) {
        if (begin_id == s.length()) {
            vector<string> path_copy;
            for (int i = 0; i < path_id; i++) path_copy.push_back(path[i]);
            partitions.push_back(path_copy);
        }
        for (int end_id = begin_id; end_id < s.length(); end_id++) {
            if (isPalindrome(s, begin_id, end_id)) {
                path[path_id] = s.substr(begin_id, end_id - begin_id + 1);
                helper(s, end_id + 1, path, path_id + 1, partitions);
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > partitions;
        if (s == "")
            return partitions;
        int L = s.length();
        vector<string> path = vector<string>(L, "");
        helper(s, 0, path, 0, partitions);
        return partitions;
    }
};