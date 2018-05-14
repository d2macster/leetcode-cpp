//
// Created by Andrii Cherniak on 5/14/18.
//
#include <queue>
#include <set>

using namespace std;

class SnakeGame {
    int s_width, s_height, sL, cur_r, cur_c;
    vector<pair<int, int>> s_food;
    queue<pair<int, int>> q;
    set<pair<int, int>> s;
    int food_id = 0;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        s_width = width;
        s_height = height;
        s_food = food;
        sL = 1;
        cur_r = cur_c = 0;
        q.push(make_pair(cur_r, cur_c));
        s.insert(make_pair(cur_r, cur_c));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int dr = 0, dc = 0;
        if (direction == "U") dr = -1;
        else if (direction == "D") dr = 1;
        else if (direction == "L") dc = -1;
        else if (direction == "R") dc = 1;
        cur_r += dr;
        cur_c += dc;
        if (cur_r < 0 || cur_r >= s_height || cur_c < 0 || cur_c >= s_width) return -1;
        if (food_id < s_food.size() && s_food[food_id].first == cur_r && s_food[food_id].second == cur_c) {
            sL++;
            food_id++;
        } else {
            s.erase(q.front());
            q.pop();
        }
        pair<int, int> p = make_pair(cur_r, cur_c);
        q.push(p);
        if (s.find(p) != s.end())
            return -1;
        s.insert(p);

        return sL - 1;
    }
};