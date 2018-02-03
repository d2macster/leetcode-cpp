//
// Created by Andrii Cherniak on 2/2/18.
//
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int L = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < L; i++) m[B[i]] = i;
        vector<int> mapping = vector<int>(L, 0);
        for (int i = 0; i < L; i++) mapping[i] = m[A[i]];
        return mapping;
    }
};