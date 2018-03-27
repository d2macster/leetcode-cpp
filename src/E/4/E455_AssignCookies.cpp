//
// Created by Andrii Cherniak on 3/27/18.
//
#include <vector>
#include <multiset>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int > cookies;
        for (int cs: s) cookies.insert(cs);
        int n = 0;
        multiset<int >::iterator it;
        sort(g.begin(), g.end());
        for (int i = g.size()-1; i >= 0; i--){
            int greed = g[i];
            it = cookies.lower_bound(greed);
            if (it != cookies.end()){
                n++;
                cookies.erase(it);
            }
        }

        return n;
    }
};