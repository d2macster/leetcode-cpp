//
// Created by Andrii Cherniak on 4/16/18.
//
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> result = vector<int>(k, 0);
        int left = 0, right = arr.size() - k;
        while(left < right){
            int mid = (left+right)/2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        for (int i = left; i < left + k; i++) result[i-left] = arr[i];
        return result;
    }
};