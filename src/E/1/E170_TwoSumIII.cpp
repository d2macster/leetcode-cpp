//
// Created by Andrii Cherniak on 2/6/18.
//
#include <unordered_map>
using std::unordered_map;

class TwoSum {
    unordered_map<int , int > m;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto p: m){
            if (2*p.first == value && p.second >= 2) return true;
            else if (value != 2* p.first && m.find(value - p.first) != m.end()) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */