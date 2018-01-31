//
// Created by Andrii Cherniak on 1/31/18.
//
#include <unordered_set>
using std::unordered_set;

class Solution {
    int transform(int n){
        int result = 0;
        int r;
        while (n > 0){
            r = n % 10;
            result += r * r;
            n /= 10;
        }
        return result;
    }
public:

    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (true){
            n = transform(n);
            if (n == 1)
                return true;
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
        }
    }
};