//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    void f_union(int v1, int v2, vector<int> &parent, vector<int> &p_size) {
        int p1 = f_find(v1, parent);
        int p2 = f_find(v2, parent);
        if (p1 == p2) return;
        int s1 = p_size[p1];
        int s2 = p_size[p2];
        if (s2 > s1) {
            parent[p1] = p2;
            p_size[p2] += s1;
        } else {
            parent[p2] = p1;
            p_size[p1] += s2;
        }
    }

    int f_find(int v, vector<int> &parent) {
        while (parent[v] != v) v = parent[v];
        return v;
    }

public:
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<pair<string, string>> pairs) {
        int L1 = words1.size();
        int L2 = words2.size();
        if (L1 != L2) return false;
        unordered_map<string, int> m;
        int N = 1;
        for (auto &p: pairs) {
            if (!m[p.first]) m[p.first] = N++;
            if (!m[p.second]) m[p.second] = N++;
        }
        vector<int> parent = vector<int>(N, 0);
        for (int i = 0; i <= N; i++) parent[i] = i;
        vector<int> p_size = vector<int>(N, 1);

        for (auto &p: pairs)
            f_union(m[p.first], m[p.second], parent, p_size);


        for (int i = 0; i < L1; i++) {
            if (words1[i] == words2[i]) continue;
            int p1 = f_find(m[words1[i]], parent);
            int p2 = f_find(m[words2[i]], parent);

            if (p1 != p2) return false;

        }
        return true;
    }
};