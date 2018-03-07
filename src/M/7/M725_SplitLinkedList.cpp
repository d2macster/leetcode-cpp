//
// Created by Andrii Cherniak on 3/6/18.
//

#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> splits = vector<ListNode *>(k, NULL);
        if (!root) return splits;
        if (k == 1) {
            splits[0] = root;
            return splits;
        }
        double L = 0;
        ListNode *p = root, *next;
        while (p) {
            p = p->next;
            L += 1;
        }
        vector<int> vl = vector<int >(k, int(L/k));

        for (int s_id = 1; s_id <= (L-k * int(L/k)); s_id++)
            vl[s_id-1]++;

        p = root;
        for (int s_id = 1; p, s_id <= k; s_id++) {
            if (vl[s_id - 1] > 0) {
                splits[s_id - 1] = p;
                for (int i = 2; i <= vl[s_id - 1]; i++)
                    p = p->next;
                next = p->next;
                p->next = NULL;
                p = next;
            }
        }

        return splits;
    }
};