//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>

using namespace std;

class Solution {
    void f_union(int v1, int v2, vector<int> & parent, vector<int> & parent_size) {
        int p1 = f_find(v1, parent);
        int p2 = f_find(v2, parent);
        if (p1 != p2){
            int s1 = parent_size[p1];
            int s2 = parent_size[p2];
            if (s1 < s2){
                parent[p1] = p2;
                parent_size[p2] += parent_size[p1];
            }else{
                parent[p2] = p1;
                parent_size[p1] += parent_size[p2];
            }
        }
    }

    int f_find(int v, vector<int> & parent) {
        while (parent[v] != v) v = parent[v];
        return v;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int> > &edges) {
        int V = 0;
        for (vector<int> &e: edges) {
            V = max(V, e[0]);
            V = max(V, e[1]);
        }
        V++;
        vector<int> parent = vector<int>(V, 0);
        vector<int> parent_size = vector<int>(V, 1);
        for (int i = 0; i < V; i++) parent[i] = i;

        for (vector<int> & e: edges){
            int p1 = f_find(e[0], parent);
            int p2 = f_find(e[1], parent);
            if (p1 == p2) return e;
            f_union(e[0], e[1], parent, parent_size);
        }

        return vector<int >();


    }
};