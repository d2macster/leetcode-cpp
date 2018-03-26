//
// Created by Andrii Cherniak on 3/26/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values, vector<pair<string, string>> queries) {

        vector<double> result = vector<double>(queries.size(), -1.0);
        unordered_map<string, int> nodes;
        int N = 1;
        for (int i = 0; i < equations.size(); i++) {
            pair<string, string> p = equations[i];
            if (nodes.find(p.first) == nodes.end())
                nodes[p.first] = N++;
            if (nodes.find(p.second) == nodes.end())
                nodes[p.second] = N++;
        }
        vector<vector<double> > dp = vector<vector<double> >(N, vector<double>(N, INT_MAX));
        vector<vector<double> > dist = vector<vector<double> >(N, vector<double>(N, INT_MAX));

        for (int i = 0; i < equations.size(); i++){
            pair<string, string> p = equations[i];
            dist[nodes[p.first]][nodes[p.second]] = values[i];
            if (values[i] != 0)
                dist[nodes[p.second]][nodes[p.first]] = 1.0/values[i];

        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                dp[i][j] = dist[i][j];
            }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][k] * dp[k][j] < dp[i][j])
                        dp[i][j] = dp[i][k] * dp[k][j];
                }
            }
        }


        for (int i = 0; i < queries.size(); i++) {
            pair<string, string> p = queries[i];
            if (nodes.find(p.first) == nodes.end() || nodes.find(p.second) == nodes.end()) result[i] = -1;
            else if (p.first == p.second) result[i] = 1.0;
            else {
                result[i] = dp[nodes[p.first]][nodes[p.second]];
                if (result[i] == INT_MAX) result[i] = -1;
            }
        }
        return result;

    }
};