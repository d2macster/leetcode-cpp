//
// Created by Andrii Cherniak on 4/8/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int L = height.size();
        if (L < 3) return 0;
        int volume = 0;
        vector<int> Lh = vector<int >(L, 0);
        vector<int> Rh = vector<int >(L, 0);
        int h = 0;
        for (int i = 0; i < L; i++){
            h = max(h, height[i]);
            Lh[i] = h;
        }
        h = 0;
        for(int i = L-1; i >= 0; i--){
            h = max(h, height[i]);
            Rh[i] = h;
        }
        for(int i = 0; i < L; i++){
            volume += max(0, min(Lh[i], Rh[i])-height[i]);
        }
        return volume;
    }
};