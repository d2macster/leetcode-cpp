//
// Created by Andrii Cherniak on 2/5/18.
//
#include <vector>
#include <queue>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::queue;


class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee* > employees, int id) {

        int answer = 0;
        unordered_map<int, Employee*> m;
        for (Employee* e: employees)
            m[e->id] = e;
        queue<int> q;
        q.push(id);

        while (!q.empty()){
            Employee* e = m[q.front()];
            q.pop();
            answer += e->importance;
            for (int s: e->subordinates) q.push(s);
        }

        return answer;
    }
};