//
// Created by Andrii Cherniak on 3/30/18.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

struct task {
    char task_name;
    int task_count;
    int available_at;
};

struct c_task_cout {
    bool operator()(const task &t1, const task &t2) {
        return t1.task_count < t2.task_count;
    }
};
struct c_available_at {
    bool operator()(const task &t1, const task &t2) {
        return t1.available_at > t2.available_at;
    }
};

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {

        if (n <= 0) return tasks.size();
        int ts = 0;
        unordered_map<char, int> counter;

        for (char t: tasks) counter[t]++;

        priority_queue<task, vector<task>, c_task_cout> q_active;
        priority_queue<task, vector<task>, c_available_at> q_cool_down;

        for (auto it: counter) {
            task t = {it.first, it.second, 0};
            q_active.push(t);
            counter[it.first]--;
        }

        while (!q_active.empty() || !q_cool_down.empty()) {
            while (!q_cool_down.empty() && q_cool_down.top().available_at <= ts){
                task t = q_cool_down.top();
                q_cool_down.pop();
                q_active.push(t);
            }
            if (!q_active.empty()){
                task t = q_active.top();
                q_active.pop();
                if (counter[t.task_name] > 0){
                    task t_next = {t.task_name, counter[t.task_name], ts + n + 1};
                    q_cool_down.push(t_next);
                    counter[t.task_name]--;
                }
            }
            ts++;
        }

        return ts;
    }
};