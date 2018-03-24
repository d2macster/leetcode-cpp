//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct comparator {
    bool operator()(int n1, int n2) {
        return n1 > n2;
    }
};

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        int L = nums.size();
        unordered_map<int, priority_queue<int, vector<int>, comparator> > sequence;
        for (int n: nums) {

            if (sequence.find(n-1) == sequence.end()) {
                sequence[n].push(1);
            } else {
                int ssize = sequence[n - 1].top();
                sequence[n - 1].pop();
                if (sequence[n - 1].empty()) sequence.erase(n-1);
                sequence[n].push(ssize + 1);
            }
        }

        for(auto it: sequence){
            if (!it.second.empty() && it.second.top() < 3)
                return false;
        }
        return true;

    }
};