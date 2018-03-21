//
// Created by Andrii Cherniak on 3/21/18.
//
#include <string>
#include <sstream>
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
    NestedInteger deserialize(istringstream &iss) {
        int number;
        char c = iss.peek();
        if (iss.peek() != '[') {
            iss >> number;
            return NestedInteger(number);
        } else {
            NestedInteger list;
            iss.get();
            while (iss.peek() != ']') {
                NestedInteger el = deserialize(iss);
                list.add(el);
                if (iss.peek() == ',') iss.get();
            }
            iss.get();
            return list;
        }
    }

public:
    NestedInteger deserialize(string s) {
        istringstream iss(s);
        return deserialize(iss);

    }
};