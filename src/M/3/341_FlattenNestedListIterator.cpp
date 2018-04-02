//
// Created by Andrii Cherniak on 4/2/18.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

void populate(vector<NestedInteger> &nestedList, stack<NestedInteger> &s) {
    if (nestedList.empty()) return;
    for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++) s.push(*it);
}


class NestedIterator {
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        populate(nestedList, s);
    }

    int next() {
        NestedInteger ni = s.top();
        s.pop();
        return ni.getInteger();
    }

    bool hasNext() {
        if (s.empty()) return false;

        while (!s.empty() && !s.top().isInteger()){
            NestedInteger ni = s.top();
            s.pop();
            populate(ni.getList(), s);
        }
        return !s.empty();
    }
};
