//
// Created by Andrii Cherniak on 1/17/18.
//
#include <list>
#include <iostream>
#include <unordered_set>

using std::list;
using std::unordered_set;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        unordered_set<int> s;
        int count = 1;
        int v = 1;
        list<int> l2;
        list<int> l3;
        list<int> l5;

        list<int> *p;

        l2.push_back(2);
        l3.push_back(3);
        l5.push_back(5);

        while (count < n) {
            p = &l2;
            if (l3.front() < p->front()) p = &l3;
            if (l5.front() < p->front()) p = &l5;
            v = p->front();
            p->pop_front();

            if (s.find(v) == s.end()) {
                s.insert(v);

                l2.push_back(v * 2);
                l3.push_back(v * 3);
                l5.push_back(v * 5);

                count++;
            }
        }


        return v;


    }
};