//
// Created by Andrii Cherniak on 2/9/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int lo = 0, hi = letters.size() - 1, mid;
        if (target >= letters[hi]) return letters[0];
        while (lo < hi){
            mid = (hi - lo)/2 + lo;
            if (letters[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        if (lo > hi) std::swap(lo, hi);
        if (letters[hi] > target && letters[lo] <= target) return letters[hi];
        else return letters[lo];
    }
};