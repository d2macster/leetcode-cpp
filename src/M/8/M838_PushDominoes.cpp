//
// Created by Andrii Cherniak on 5/23/18.
//
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    string pushDominoes(string dominoes) {
        int L = dominoes.size();
        vector<bool > visited = vector<bool >(L, false);
        vector<int> lr = vector<int>(L, 0);
        unordered_set<int> points;
        for (int i = 0; i < L; i++){
            if (dominoes[i] == 'L') {
                points.insert(i);
                visited[i] = true;
                lr[i] = -1;
            }
            if (dominoes[i] == 'R') {
                points.insert(i);
                visited[i] = true;
                lr[i] = 1;
            }
        }
        while (!points.empty()){
            unordered_set<int> next_points;
            for (int p: points){
                if (lr[p] == -1 && p > 0 && !visited[p-1]){
                    next_points.insert(p-1);
                    lr[p-1] --;
                }
                if (lr[p] == 1 && p < L - 1 && !visited[p+1]){
                    next_points.insert(p+1);
                    lr[p+1]++;
                }
            }
            points.clear();
            for (int p: next_points) {
                visited[p] = true;
                if (lr[p] != 0) points.insert(p);
            }
        }
        for (int i = 0; i < L; i++){
            if (lr[i] == 0) dominoes[i] = '.';
            else if (lr[i] == 1) dominoes[i] = 'R';
            else if (lr[i] == -1) dominoes[i] = 'L';
        }
        return dominoes;
    }
};