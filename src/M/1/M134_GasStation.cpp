//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {

public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        vector<int> diff = vector<int>(N, 0);
        int gas_balance = 0;
        int lowest_balance = INT_MAX;
        int start_id = 0;
        for(int i = 0; i < N; i++) {
            diff[i] = gas[i] - cost[i];
            gas_balance += diff[i];
            if (gas_balance < lowest_balance){
                lowest_balance = gas_balance;
                start_id = i;
            }
        }
        if (gas_balance < 0) return -1;
        return (start_id + 1)%N;
    }
};