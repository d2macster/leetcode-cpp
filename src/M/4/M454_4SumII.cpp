//
// Created by Andrii Cherniak on 4/4/18.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int , int> sumAB;
        for(int a: A)
            for(int b: B)
                sumAB[a+b]++;

        int counter = 0;
        for(int c: C)
            for (int d:D)
                if (sumAB.find(-(c+d)) != sumAB.end()) counter += sumAB[-(c+d)];

        return counter;

    }
};