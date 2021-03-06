//
// Created by Andrii Cherniak on 4/6/18.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result = vector<string>(n, "");
        for (int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0) result[i-1] = "FizzBuzz";
            else if (i % 3 == 0) result[i-1] = "Fizz";
            else if (i % 5 == 0) result[i-1] = "Buzz";
            else result[i-1] = to_string(i);
        }

        return result;
    }
};