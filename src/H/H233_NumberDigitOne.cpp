//
// Created by Andrii Cherniak on 5/22/18.
//

class Solution {
public:
    int countDigitOne(int n) {
        long result = 0L;
        long divider = 1L;
        long nn = long(n);

        for (long d = 1; d <= nn; d *= 10) {
            long a = n / d;
            long b = n % d;
            long ad = a % 10;
            if (ad >= 2) result += ((a / 10) + 1) * d;
            else if (ad == 1) result += (a / 10) * d + (b + 1);
            else result += (a / 10) * d;
        }
        return result;
    }
};