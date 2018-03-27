//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>

using namespace std;

class Solution {
    int components = 0;
    void f_union(int v1, int v2, vector<int> &parent, vector<int> &parent_size) {
        int p1 = f_find(v1, parent);
        int p2 = f_find(v2, parent);
        if (p1 != p2) {
            components--;
            int s1 = parent_size[p1];
            int s2 = parent_size[p2];
            if (s1 < s2) {
                parent[p1] = p2;
                parent_size[p2] += parent_size[p1];
            } else {
                parent[p2] = p1;
                parent_size[p1] += parent_size[p2];
            }
        }
    }

    int f_find(int v, vector<int> &parent) {
        while (parent[v] != v) v = parent[v];
        return v;
    }

public:
    int countComponents(int n, vector<pair<int, int> > &edges) {
        components = n;
        vector<int> parent = vector<int>(n, 0);
        vector<int> parent_size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto & e: edges) f_union(e.first, e.second, parent, parent_size);

        return components;
    }
};