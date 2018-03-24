//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>

using namespace std;

struct next_pair {
    int id1;
    int id2;
    int val;
};

struct comparator {
    bool operator()(const next_pair &np1, const next_pair &np2) {
        return np1.val > np2.val;
    }
};

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int> > result;
        int L1 = nums1.size();
        int L2 = nums2.size();
        if (!L1 || !L2)
            return result;

        k = min(k, L1 * L2);

        next_pair np = {0, 0, nums1[0] + nums2[0]};

        priority_queue<next_pair, vector<next_pair>, comparator> q;
        q.push(np);

        for (int p_id = 1; p_id <= k; p_id++) {
            next_pair np = q.top();
            q.pop();
            pair<int, int> p = make_pair(nums1[np.id1], nums2[np.id2]);
            result.push_back(p);
            if (np.id1 + 1 < L1) {
                next_pair np_next = {np.id1 + 1, np.id2, nums1[np.id1 + 1] + nums2[np.id2]};
                q.push(np_next);
            }
            if (np.id1 == 0 && np.id2 + 1 < L2) {
                next_pair np_next = {np.id1, np.id2 + 1, nums1[np.id1] + nums2[np.id2 + 1]};
                q.push(np_next);
            }
        }
        return result;
    }
};