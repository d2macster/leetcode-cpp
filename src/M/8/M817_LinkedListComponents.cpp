//
// Created by Andrii Cherniak on 5/23/18.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    int components = 0;
    unordered_map<int, int> parent;
    unordered_map<int, int> s;

    int find_f(int v){
        while (parent[v] != v) v = parent[v];
        return v;
    }

    void union_f(const int v1, const int v2){
        int p1 = find_f(v1);
        int p2 = find_f(v2);
        if (p1 == p2) return;
        int s1 = s[p1];
        int s2 = s[p2];
        if (s1 >= s2){
            parent[p2] = p1;
            s[p1] = s1 + s2;
        }else{
            parent[p1] = p2;
            s[p2] = s1 + s2;
        }
        components--;
    }
public:
    int numComponents(ListNode *head, vector<int> &G) {
        components = G.size();
        if (!head) return components;
        for(int v: G) {
            parent[v] = v;
            s[v] = 1;
        }
        int prev = head->val;
        head = head->next;
        while (head != NULL){
            if (parent.find(prev) != parent.end() && parent.find(head->val) != parent.end())
                union_f(prev, head->val);
            prev = head->val;
            head = head->next;
        }

        return components;
    }
};