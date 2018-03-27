//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    void f_union(int v1, int v2, vector<int> &parent, vector<int> &parent_size) {
        int p1 = f_find(v1, parent);
        int p2 = f_find(v2, parent);
        if (p1 != p2) {
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
    vector<vector<string> > accountsMerge(vector<vector<string> > &accounts) {
        unordered_map<string, vector<int> > email_accounts;
        int aL = accounts.size();
        for (int i = 0; i < aL; i++) {
            for (int j = 1; j < accounts[i].size(); j++)
                email_accounts[accounts[i][j]].push_back(i);
        }

        vector<int> parent = vector<int>(aL, 0);
        for (int i = 0; i < aL; i++) parent[i] = i;
        vector<int> p_size = vector<int>(aL, 1);

        for (auto it: email_accounts) {

            vector<int> ac_list = it.second;
            for (int i = 0; i < ac_list.size() - 1; i++)
                for (int j = i + 1; j < ac_list.size(); j++)
                    f_union(ac_list[i], ac_list[j], parent, p_size);
        }

        vector<vector<string> > new_accounts;
        vector<string> names = vector<string>(aL, "");
        vector<unordered_set<string> > emails = vector<unordered_set<string> >(aL, unordered_set<string>());
        for (int i = 0; i < aL; i++){
            int p = f_find(i, parent);
            names[p] = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++){
                emails[p].insert(accounts[i][j]);
            }
        }

        for (int i = 0; i < aL; i++){
            if (names[i] != ""){
                vector<string> acc;
                acc.push_back(names[i]);
                for(string e: emails[i]) acc.push_back(e);
                sort(acc.begin()+1, acc.end());
                new_accounts.push_back(acc);
            }
        }


        return new_accounts;

    }
};