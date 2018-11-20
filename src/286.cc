#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "utils.h"

using namespace std;

vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};

void bfs(vector<vector<int>>& rooms, queue<pair<int,int>>& q)
{
    int r, c, x, y;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (auto& dir : dirs) {
            x = r + dir.first;
            y = c + dir.second;
            if (x<0 || x>=rooms.size() || y<0 || y>=rooms[0].size() || rooms[x][y]==-1)
                continue;
            if (rooms[r][c]+1 < rooms[x][y]) {
                rooms[x][y] = rooms[r][c] + 1;
                q.emplace(x, y);
            }
        }
    }
}

void wallsAndGates(vector<vector<int>>& rooms)
{
    int i, j;
    queue<pair<int,int>> q;


    for (i=0; i<rooms.size(); ++i) {
        for (j=0; j<rooms[0].size(); ++j) {
            if (rooms[i][j] == 0)
                q.emplace(i, j);
        }
    }

    bfs(rooms, q);
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{ INT_MAX,-1,0,INT_MAX },
                                     { INT_MAX,INT_MAX,INT_MAX,-1 },
                                     { INT_MAX,-1,INT_MAX,-1 },
                                     { 0,-1,INT_MAX,INT_MAX }};

    wallsAndGates(test_case);

    for (auto& v : test_case) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
