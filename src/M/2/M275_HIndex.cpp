//
// Created by Andrii Cherniak on 5/25/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int L = citations.size();
        int l = 0, r = L-1;
        while (l < r-1){
            int mid = (r + l)/2;
            if (citations[mid] >= L - mid){
                h = max(h, L - mid);
                r = mid - 1;
            }else l = mid + 1;
        }
        for(int i = l; i <= r; i++){
            if (citations[i] >= L - i) h = max(h, L - i);
        }
        return h;
    }
};