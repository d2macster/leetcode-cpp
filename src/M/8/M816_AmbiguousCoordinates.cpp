//
// Created by Andrii Cherniak on 4/16/18.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool isValid(string &S, int left, int right) {
        if (left == right) return true;
        int L = right - left + 1;
        int begin_zeros = 0, end_zeros = 0;
        for (int i = left; i <= right && S[i] == '0'; i++) begin_zeros++;
        if (begin_zeros == L) return false;
        if (begin_zeros > 0 && S[right] == '0') return false;
        return true;
    }

    vector<string> generate(string &S, int left, int right) {
        vector<string> ss;
        if (left == right) ss.push_back(S.substr(left, 1));
        else{
            if (S[left] == '0') ss.push_back("0." + S.substr(left + 1, right - left));
            else if (S[right] == '0') ss.push_back(S.substr(left, right - left + 1));
            else{
                ss.push_back(S.substr(left, right - left + 1));
                for (int m = left + 1; m <= right; m++)
                    ss.push_back(S.substr(left, m - left) + "." + S.substr(m, right - m + 1));
            }
        }
        return ss;
    }

public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> coords;
        int L = S.size();
        int left = 1, right = L - 2;
        for (int mid = 0; mid <= right - 1; mid++) {
            if (isValid(S, left, mid) && isValid(S, mid + 1, right)) {

                vector<string> ss1 = generate(S, left, mid);
                vector<string> ss2 = generate(S, mid + 1, right);
                for (string &s1: ss1)
                    for (string &s2: ss2) coords.push_back("(" + s1 + ", " + s2 + ")");
            }
        }
        return coords;
    }
};