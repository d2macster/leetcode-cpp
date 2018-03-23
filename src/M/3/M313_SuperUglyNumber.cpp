//
// Created by Andrii Cherniak on 3/23/18.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct next_ugly {
    int number_id;
    int prime_number;
    int val;
};

struct comparator {
    bool operator()(const next_ugly &nu1, const next_ugly &nu2) {
        return nu1.val > nu2.val;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        if (n <= 1)
            return 1;
        vector<int> numbers = vector<int>(n, 1);
        priority_queue<next_ugly, vector<next_ugly>, comparator> q;
        for (int p: primes) {
            next_ugly nu = {0, p, p};
            q.push(nu);
        }
        int i = 2;
        for (; i <= n; ) {
            next_ugly nu = q.top();
            q.pop();
            if (nu.val > numbers[i-2]) {
                numbers[i - 1] = nu.val;
                i++;
            }

            next_ugly nu_next = {nu.number_id + 1, nu.prime_number, numbers[nu.number_id + 1]*nu.prime_number};
            q.push(nu_next);
        }
        return numbers[n - 1];
    }
};