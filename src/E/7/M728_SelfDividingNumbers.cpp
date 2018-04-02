//
// Created by Andrii Cherniak on 4/2/18.
//
#include <vector>
using namespace std;

class Solution {
    bool check(int n){
        int i = n;
        while (i > 0){
            int r = i % 10;
            if (r == 0 || n % r != 0) return false;
            i /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++){
            if (check(i)) result.push_back(i);
        }
        return result;
    }
};