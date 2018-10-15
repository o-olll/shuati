#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void bfs(vector<vector<int>>& grid, int r, int c, vector<vector<pair<int,int>>>& dist);

int shortestDistance(vector<vector<int>>& grid)
{
    vector<vector<pair<int,int>>> dist(grid.size(), vector<pair<int,int>>(grid[0].size(), {0,0}));
    int i, j, bldgs = 0, res = INT_MAX;

    for (i=0; i<grid.size(); ++i) {
        for (j=0; j<grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                ++bldgs;
                bfs(grid, i, j, dist);
            }
        }
    }

    for (i=0; i<grid.size(); ++i) {
        for (j=0; j<grid[0].size(); ++j) {
            if (dist[i][j].second == bldgs)
                res = min(res, dist[i][j].first);
        }
    }

    return res == INT_MAX ? -1 : res;
}

void bfs(vector<vector<int>>& grid, int r, int c, vector<vector<pair<int,int>>>& dist)
{
    vector<vector<int>> tempDist(grid.size(), vector<int>(grid[0].size()));
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>> q;
    int steps = 0, n, x, y;

    q.emplace(r, c);

    while (!q.empty()) {
        n = q.size();
        ++steps;
        while (n-- > 0) {
            pair<int,int> node = q.front();
            q.pop();
            for (auto& dir : dirs) {
                x = dir.first + node.first;
                y = dir.second + node.second;
                if (x<0 || x>=grid.size() ||
                    y<0 || y>=grid[0].size() ||
                    grid[x][y]!=0 || visited[x][y]) {
                    continue;
                }
                visited[x][y] = true;
                tempDist[x][y] = steps;
                q.emplace(x, y);
            }
        }
    }

    for (x=0; x<dist.size(); ++x) {
        for (y=0; y<dist[0].size(); ++y) {
            if (grid[x][y]==0 && visited[x][y]) {
                dist[x][y].first += tempDist[x][y];
                ++dist[x][y].second;
            }
        }
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,0,0,0,1},
                                     {0,0,2,0,0},
                                     {0,0,1,0,0}};

    cout << shortestDistance(test_case) << endl;

    return 0;
}
