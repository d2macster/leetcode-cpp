//
// Created by Andrii Cherniak on 2/7/18.
//
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string result = (numerator < 0 ^ denominator < 0)? "-" : "";

        long n = abs(long(numerator));
        long d = abs(long(denominator));
        result += std::to_string(n / d);
        if (n % d  == 0)
            return result;

        result += '.';
        unordered_map<long, int> m;
        long r = n % d;
        while (r > 0){
            if (m.find(r) != m.end()){
                result.insert(m[r], 1, '(');
                result += ')';
                return result;
            }
            m[r] = result.size();
            r *= 10;
            result += std::to_string(r/d);
            r %= d;
        }

        return result;
    }
};