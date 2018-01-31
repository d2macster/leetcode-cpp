//
// Created by Andrii Cherniak on 1/31/18.
//
#include <vector>

using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int L = flowerbed.size();
        if (n > L) return false;
        if (n == 0)
            return true;
        int new_flowers = 0;
        bool left, right;
        for (int i = 0; i < L; i++) {
            if (flowerbed[i] == 0) {
                left = (i == 0) ? false : (flowerbed[i - 1] == 1);
                right = (i == (L - 1)) ? false : (flowerbed[i + 1] == 1);
                if (!left && !right) {
                    flowerbed[i] = 1;
                    new_flowers++;
                    if (new_flowers >= n) return true;
                }
            }
        }
        return false;
    }
};