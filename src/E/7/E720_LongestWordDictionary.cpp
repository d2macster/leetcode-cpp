//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    string longestWord(vector<string> &words) {
        unordered_set<string> s;
        for (string &w: words) s.insert(w);
        string answer = "";
        for (string &w: words){
            int i = 1;
            int wL = w.length();
            for (; i < wL; i ++)
            if (s.find(w.substr(0, i)) == s.end()) break;
            if (i == wL){
                if (wL > answer.length()) answer = w;
                else if (wL == answer.length()) answer = std::min(answer, w);
            }
        }
        return answer;
    }
};