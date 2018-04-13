//
// Created by Andrii Cherniak on 4/13/18.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
    void generator(vector<string> &result, int n, int pos, string &ss, vector<int> &mirror){
        if (pos <= n/2){
            for(int d : (int[]){0, 1, 6, 8, 9}) {
                ss[pos-1] = '0' + d;
                generator(result, n, pos+1, ss, mirror);
            }
        }else if (n % 2 == 1 && (pos == n / 2 + 1)){
            for(int d : (int[]){0, 1, 8}) {
                ss[pos-1] = '0' + d;
                generator(result, n, pos+1, ss, mirror);
            }
        } else{
            for(int i = pos; i <= n; i++){
                int v = ss[n-i] - '0';
                int vm = mirror[v];
                ss[i-1] = '0'+vm;
            }
            if (n == 1 || ss[0] != '0')
            result.push_back(ss);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector<int> mirror = vector<int>(10, 0);
        mirror[0] = 0;
        mirror[1] = 1;
        mirror[6] = 9;
        mirror[8] = 8;
        mirror[9] = 6;

        vector<string> result;
        if (n < 1) return result;
        string ss = "";
        for (int i = 1; i <= n; i++) ss += " ";
        generator(result, n, 1, ss, mirror);
        return result;

    }
};