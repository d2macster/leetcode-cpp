//
// Created by Andrii Cherniak on 2/9/18.
//

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    return (version >= 2);
}

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = (hi - lo) / 2 + lo;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        }
        if (lo > hi) std::swap(lo, hi);
        if (isBadVersion(hi) && !isBadVersion(lo)) return hi;
        else return lo;
    }
};