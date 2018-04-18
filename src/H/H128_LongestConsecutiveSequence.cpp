//
// Created by Andrii Cherniak on 4/18/18.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<int> find_f(int i, vector<vector<int>> &union_find) {
        while (union_find[i][0] != i) i = union_find[i][0];
        vector<int> answer = vector<int>(2, 0);
        answer[0] = i;
        answer[1] = union_find[i][1];
        return answer;
    }

    void union_f(int i, int j, vector<vector<int>> &union_find) {
        vector<int> i_parent = find_f(i, union_find);
        vector<int> j_parent = find_f(j, union_find);

        if (i_parent[0] == j_parent[0]) return;

        if (i_parent[1] > j_parent[1]){
            union_find[j_parent[0]][0] = i_parent[0];
            union_find[i_parent[0]][1] += j_parent[1];
        }else{
            union_find[i_parent[0]][0] = j_parent[0];
            union_find[j_parent[0]][1] += i_parent[1];
        }

    }

public:
    int longestConsecutive(vector<int> &nums) {
        int L = nums.size();
        if (L <= 1) return L;
        vector<vector<int>> union_find = vector<vector<int>>(L, vector<int>(2, 0));
        unordered_map<int, int> num_ids;

        for (int i = 0; i < L; i++) {
            num_ids[nums[i]] = i;
            union_find[i][0] = i;
            union_find[i][1] = 1;
        }

        for (int i = 0; i < L; i++) {
            int n = nums[i];
            if (num_ids.find(n - 1) != num_ids.end()) union_f(num_ids[n], num_ids[n - 1], union_find);
            if (num_ids.find(n + 1) != num_ids.end()) union_f(num_ids[n], num_ids[n + 1], union_find);
        }
        int answer = 0;
        for (int i = 0; i < L; i++) answer = max(answer, union_find[i][1]);
        return answer;
    }
};