//
// Created by Andrii Cherniak on 3/15/18.
//
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    void write_helper(vector<char> &chars, char ch, int cnt, int &write_id) {
        chars[write_id++] = ch;
        if (cnt > 1) {
            vector<char> digits;
            while (cnt > 0) {
                digits.push_back('0' + (cnt % 10));
                cnt /= 10;
            }
            reverse(digits.begin(), digits.end());
            for (char d: digits) {
                chars[write_id++] = d;
            }
        }
    }

public:
    int compress(vector<char> &chars) {
        int L = chars.size();
        if (L <= 1)
            return L;

        char prev_ch = chars[0];
        int cnt = 1, write_id = 0;
        for (int i = 1; i < L; i++) {
            if (prev_ch == chars[i]) cnt++;
            else {
                write_helper(chars, prev_ch, cnt, write_id);
                cnt = 1;
                prev_ch = chars[i];
            }
        }
        write_helper(chars, prev_ch, cnt, write_id);

        return write_id;
    }
};