//
// Created by Andrii Cherniak on 3/20/18.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<int> parser(string &version) {
        vector<int> vv = vector<int>(1, 0);
        int v_id = 0;
        for (char c: version) {
            if (c == '.') {
                vv.push_back(0);
                v_id++;
            } else
                vv[v_id] = vv[v_id] * 10 + (c - '0');
        }
        return vv;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> pv1 = parser(version1);
        vector<int> pv2 = parser(version2);
        int L1 = pv1.size();
        int L2 = pv2.size();
        for (int i = 0; i < min(L1, L2); i++){
            if (pv1[i] > pv2[i]) return 1;
            else if (pv1[i] < pv2[i]) return -1;
        }
        if (L1 > L2) for (int i = L2; i < L1; i++) if (pv1[i] > 0) return 1;
        if (L1 < L2) for (int i = L1; i < L2; i++) if (pv2[i] > 0) return -1;

        return 0;
    }
};