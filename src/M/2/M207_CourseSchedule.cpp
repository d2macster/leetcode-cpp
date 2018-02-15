//
// Created by Andrii Cherniak on 2/14/18.
//
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;

class Solution {
    bool hasCycle(vector<vector<int> > &depends_on, vector<bool> &visited, vector<bool> &path, int course) {
        visited[course] = true;
        path[course] = true;
        for (int c : depends_on[course])
            if (path[c] || hasCycle(depends_on, visited, path, c)) return true;
        path[course] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int> > &prerequisites) {
        vector<vector<int> > depends_on = vector<vector<int> >(numCourses, vector<int>());
        for (pair<int, int> p:prerequisites)
            depends_on[p.first].push_back(p.second);

        vector<bool> visited = vector<bool>(numCourses, false);
        vector<bool> path = vector<bool>(numCourses, false);


        for (int c = 0; c < numCourses; c++)
            if (!visited[c] && hasCycle(depends_on, visited, path, c)) return false;

        return true;

    }
};