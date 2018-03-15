//
// Created by Andrii Cherniak on 3/15/18.
//
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int nums_id = m[val];
        if (nums_id != nums.size() - 1) {
            int n_swap = nums[nums.size() - 1];
            m[n_swap] = nums_id;
            nums[nums_id] = n_swap;
        }
        nums.erase(--nums.end());
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[random()%nums.size()];
    }
};