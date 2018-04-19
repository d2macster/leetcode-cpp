//
// Created by Andrii Cherniak on 4/19/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int answer = 0;

    void mergeSort(vector<long> &sum, vector<long> &tmp, int left, int right, long l, long u) {
        if (left >= right) return;

        int mid = (left + right) / 2;
        mergeSort(sum, tmp, left, mid, l, u);
        mergeSort(sum, tmp, mid + 1, right, l, u);


        int m = mid + 1;
        int n = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (m <= right && (sum[m] - sum[i]) < l)m++;
            while (n <= right && (sum[n] - sum[i]) <= u)n++;
            answer += n - m;

        }
        for (int i = left; i <= right; i++) tmp[i] = sum[i];

        int pos = left;
        int i = left, j = mid + 1;
        while (i <= mid || j <= right) {
            if (i <= mid && j <= right) {
                if (tmp[i] < tmp[j]) sum[pos] = tmp[i++];
                else sum[pos] = tmp[j++];
            } else if (i <= mid)sum[pos] = tmp[i++];
            else sum[pos] = tmp[j++];
            pos++;
        }

    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int L = nums.size();
        vector<long> sum = vector<long>(L + 1, 0L);
        vector<long> tmp = vector<long>(L + 1, 0L);

        long s = 0L;
        for (int i = 1; i <= L; i++)
            sum[i] = sum[i - 1] + nums[i - 1];

        mergeSort(sum, tmp, 0, sum.size() - 1, long(lower), long(upper));

        return answer;
    }
};