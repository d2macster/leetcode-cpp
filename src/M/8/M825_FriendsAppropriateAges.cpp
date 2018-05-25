//
// Created by Andrii Cherniak on 5/25/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        int requests = 0;
        sort(ages.begin(), ages.end());

        int L = ages.size();
        int r = L-1;
        int l = r - 1;
        while (r > 0){
            int cur_age = ages[r];
            while ((l - 1 >= 0) && (ages[l-1]> 0.5*cur_age + 7))l--;

            int cur_req = max(0, r - l);
            while (r >= 0 && ages[r] == cur_age){
                requests += cur_req;
                r--;
            }
        }
        return requests;
    }
};