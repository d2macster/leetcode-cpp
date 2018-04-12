//
// Created by Andrii Cherniak on 4/12/18.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int L = arr.size();
        if (L <= 1) return L;
        unordered_set<int> expected, observed;
        int chunks = 0;
        for(int i = 0; i < L; i++){
            expected.insert(i);
            observed.insert(arr[i]);
            if (expected == observed){
                chunks++;
                expected.clear();
                observed.clear();
            }
        }

        return chunks;
    }
};