//
// Created by Andrii Cherniak on 2/4/18.
//

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        bool primes[n+1];
        for (int i = 0; i <= n; i++) primes[i] = true;
        int cnt = 0;
        for (int i = 2; i < n; i++){
            if (primes[i]){
                cnt++;
                for (int j = i * 2; j <= n; j+= i) primes[j] = false;
            }
        }
        return cnt;
    }
};