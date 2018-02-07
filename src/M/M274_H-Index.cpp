//
// Created by Andrii Cherniak on 2/7/18.
//
#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int L = citations.size();
        map<int, int> counter, cum_sum;
        for (int c: citations) counter[c] ++;
        map<int, int>::iterator it;
        map<int, int>::reverse_iterator rit;
        int sum = 0;
        for(rit = counter.rbegin(); rit != counter.rend(); rit++){
            sum += rit->second;
            cum_sum[rit->first] = sum;
        }

        int h = 0;
        for(it = cum_sum.begin(); it != cum_sum.end(); it++)
            h = std::max(h, std::min(it->first, it->second));

        return h;
    }
};