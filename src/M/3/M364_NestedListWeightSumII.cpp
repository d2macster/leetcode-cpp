//
// Created by Andrii Cherniak on 3/28/18.
//
#include <vector>
#include <iostream>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    void helper(NestedInteger &ni, int d, vector<int> &niv, vector<int> &nid) {
        if (ni.isInteger()) {
            niv.push_back(ni.getInteger());
            nid.push_back(d);
        }
        else {
            for (NestedInteger & ni_next : ni.getList()) helper(ni_next, d + 1, niv, nid);
        }
    }

public:
    int depthSumInverse(vector<NestedInteger> &nestedList) {
        int sum = 0;
        vector<int> niv = vector<int>();
        vector<int> nid = vector<int>();
        for (auto & ni: nestedList) helper(ni, 1, niv, nid);
        int maxD = 1;
        for (int d: nid) maxD = max(maxD, d);
        for (int i = 0; i < niv.size(); i++)
            sum += niv[i] *(maxD - nid[i] + 1);
        return sum;
    }
};