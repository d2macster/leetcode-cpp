//
// Created by Andrii Cherniak on 4/19/18.
//
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string input) {

        if (dp.find(input) != dp.end())
            return dp[input];

        vector<int> answer;
        int L = input.size();
        if (L == 0) return answer;

        bool has_operations = false;

        for (int i = 0; i < L; i++){
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
                has_operations = true;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, L-i-1));
                for (int l: left)
                    for (int r: right){
                        if (input[i] == '+') answer.push_back(l+r);
                        else if (input[i] == '-') answer.push_back(l-r);
                        else if (input[i] == '*') answer.push_back(l*r);
                    }
            }
        }
        if (!has_operations) answer.push_back(stoi(input));
        dp[input] = answer;

        return answer;
    }
};