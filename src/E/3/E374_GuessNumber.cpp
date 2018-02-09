//
// Created by Andrii Cherniak on 2/8/18.
//

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

int guess(int num) {
    int target = 6;
    if (num == target) return 0;
    else if (num > target) return -1;
    else return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n, mid, g;
        while (lo < hi) {

            mid = (hi - lo)/2 + lo;
            g = guess(mid);

            if (g == 0) return mid;
            else if (g == 1) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};