#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food):
        _board(height, vector<bool>(width, false)),
        _mark(0), _w(width), _h(height),
        _food(food.rbegin(), food.rend())
    {
        if (width>0 && height>0)
            _board[0][0] = true;
        _dirs["U"] = {-1, 0};
        _dirs["D"] = {1, 0};
        _dirs["L"] = {0, -1};
        _dirs["R"] = {0, 1};
        _snake.emplace(0, 0);
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int r, c;
        r = _snake.back().first + _dirs[direction].first;
        c = _snake.back().second + _dirs[direction].second;
        if (r<0 || r>=_h || c<0 || c>=_w || _board[r][c])
            return -1;

        _snake.emplace(r, c);
        _board[r][c] = true;
        if (r!=_food.back().first || c!=_food.back().second) {
            _board[_snake.front().first][_snake.front().second] = false;
            _snake.pop();
        } else {
            _food.pop_back();
        }

        // printf("Head %d %d, tail %d %d\n", _snake.back().first, _snake.back().second,
        //                 _snake.front().first, _snake.front().second);

        return _snake.size() - 1;
    }

private:
    vector<vector<bool>> _board;
    vector<pair<int, int>> _food;
    queue<pair<int,int>> _snake;
    int _w, _h, _mark;
    unordered_map<string, pair<int,int>> _dirs;
};

int main(int argc, char** argv)
{
    vector<pair<int,int>> food = {{1,2},{4,2},{3,4},{1,6},{4,6}};

    SnakeGame game(8, 6, food);
    int res = 0;
    string dir;

    while (res >= 0) {
        cin >> dir;
        res = game.move(dir);
        cout << res << endl;
    }

    return 0;
}
