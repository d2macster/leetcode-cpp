//
// Created by Andrii Cherniak on 4/18/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int counter = 0;
    void mergeSort(vector<int> &merge, vector<int> &tmp, int left, int right) {
        if (left >= right) return;
        int mid = (left + right)/2;
        mergeSort(merge, tmp, left, mid);
        mergeSort(merge, tmp, mid + 1, right);

        // two pointers

        int i = left, j = mid+1;
        while (i <= mid && j <= right){
            if (long(merge[i]) > 2*long(merge[j])){
                counter += (mid - i + 1);
                j++;
            } else i++;
        }

        for (int i = left; i <= right; i++) tmp[i] = merge[i];
        int pos = left;
        i = left, j = mid+1;
        while (i <= mid || j <= right){
            if (i <= mid && j <= right){
                if (tmp[i] < tmp[j]) merge[pos] = tmp[i++];
                else merge[pos] = tmp[j++];
            }else if (i <= mid) merge[pos] = tmp[i++];
            else merge[pos] = tmp[j++];
            pos++;
        }

    }

public:
    int reversePairs(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1) return 0;
        vector<int> merge = vector<int>(L, 0);
        vector<int> tmp = vector<int>(L, 0);


        for (int i = 0; i < L; i++) merge[i] = nums[i];

        mergeSort(merge, tmp, 0, L-1);
        return counter;
    }
};