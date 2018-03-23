//
// Created by Andrii Cherniak on 3/23/18.
//
#include <cmath>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int> > helper(int n, int begin) {
        vector<vector<int> > factors;
        vector<int> vn = vector<int>(1, n);
        factors.push_back(vn);
        for (int p = begin; p <= sqrt(n); p++){
            if (n % p == 0 && n/p >= p){
                vector<vector<int> > fnp = helper(n/p, p);
                for(vector<int> fnpv: fnp){
                    fnpv.insert(fnpv.begin(), p);
                    factors.push_back(fnpv);
                }
            }
        }
        return factors;
    }
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > factors = helper(n, 2);
        factors.erase(factors.begin());
        return factors;
    }
};