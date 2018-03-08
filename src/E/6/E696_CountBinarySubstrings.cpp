//
// Created by Andrii Cherniak on 3/7/18.
//
#include <string>

using std::string;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int L = s.length();
        int result = 0;
        int prevCnt = 0, curCnt = 1, cnt = 0;
        for (int i = 1; i < L; i++){
            if (s[i] == s[i-1]) {
                curCnt++;
            }
            else{
                result += cnt;
                cnt = 0;
                prevCnt = curCnt;
                curCnt = 1;
            }
            cnt = std::max(cnt, std::min(prevCnt, curCnt));
        }
        result += cnt;
        return result;
    }
};