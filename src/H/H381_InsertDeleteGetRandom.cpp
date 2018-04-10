//
// Created by Andrii Cherniak on 4/10/18.
//
#include <unordered_map>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
    vector<int > nums;
    unordered_map<int , set<int > > num_ids;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {

        nums.push_back(val);
        num_ids[val].insert(nums.size()-1);
        return num_ids[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (num_ids.find(val) == num_ids.end()) return false;
        int val_id = *(--num_ids[val].end());
        int nums_last = nums[nums.size()-1];
        num_ids[nums_last].erase(nums.size()-1);
        num_ids[nums_last].insert(val_id);
        nums[val_id] = nums_last;

        num_ids[val].erase(val_id);
        if (num_ids[val].empty()) num_ids.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        if (nums.size() == 0) return 0;
        return nums[rand() % nums.size()];
    }
};