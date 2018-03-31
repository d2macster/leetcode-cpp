//
// Created by Andrii Cherniak on 3/30/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> partitions;
        if (S == "")
            return partitions;
        int L = S.size();
        vector<int> last_id = vector<int>(26, 0);
        for (int i = 0; i < L; i++) last_id[S[i] - 'a'] = i;

        int s_id = 0;
        int to_expand = 0;
        while (s_id < L) {
            while (s_id <= to_expand) {
                to_expand = max(to_expand, last_id[S[s_id] - 'a']);
                s_id++;
            }
            partitions.push_back(s_id);
            to_expand = s_id;
        }
        for (int i = partitions.size() - 1; i >= 1; i--) partitions[i] -= partitions[i - 1];

        return partitions;
    }
};