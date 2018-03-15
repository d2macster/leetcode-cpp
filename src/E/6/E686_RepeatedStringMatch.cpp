//
// Created by Andrii Cherniak on 3/15/18.
//
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        unordered_set<char> sa, sb;
        for (char ch: A) sa.insert(ch);
        for (char ch: B) if (sa.find(ch) == sa.end()) return -1;
        int La = A.length();
        int Lb = B.length();
        for (int a_begin = 0; a_begin < La; a_begin++) {
            int a_id = a_begin;
            int b_id = 0;
            while (A[a_id % La] == B[b_id] && b_id < Lb) {
                a_id++;
                b_id++;
            }
            if (b_id == Lb) return (a_id / La) + (a_id % La > 0);
        }
        return -1;
    }
};