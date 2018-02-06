//
// Created by Andrii Cherniak on 2/6/18.
//
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        int L1 = list1.size();
        int L2 = list2.size();
        vector<string> list;
        if (L1 == 0 || L2 == 0) return list;
        unordered_map<string, int> l1m(L1);

        int key, min_key = L1 + L2;

        for (int i = 0; i < L1; i++) l1m[list1[i]] = i;
        for (int i = 0; i < L2; i++) {
            if (l1m.find(list2[i]) != l1m.end()) {
                key = l1m[list2[i]] + i;
                if (key < min_key) {
                    list.clear();
                    min_key = key;
                    list.push_back(list2[i]);
                } else if (key == min_key)
                    list.push_back(list2[i]);
            }
        }

        return list;
    }
};