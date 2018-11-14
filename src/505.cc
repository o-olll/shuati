#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "utils.h"

using namespace std;
using Node = pair<int, pair<int,int>>;

vector<pair<int,int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    Node node;
    int d, x, y;
    set<Node> q;
    vector<vector<int>> dists(maze.size(), vector<int>(maze[0].size(), INT_MAX));

    dists[start[0]][start[1]] = 0;
    q.emplace(0, make_pair(start[0], start[1]));

    while (!q.empty()) {
        node = *q.begin();
        q.erase(q.begin());

        //        printf("--- (%d, %d) : %d ---\n", node.second.first, node.second.second, node.first);
        if (node.second.first==destination[0] && node.second.second==destination[1])
            return node.first;

        for (auto& dir : dirs) {
            x = node.second.first;
            y = node.second.second;
            d = node.first;
            while (x>=0 && x<maze.size() && y>=0 && y<maze[0].size() &&
                   maze[x][y]!=1) {
                x += dir.first;
                y += dir.second;
                ++d;
            }
            x -= dir.first;
            y -= dir.second;
            --d;

            if (dists[x][y] > d) {
                Node tmp(dists[x][y], make_pair(x, y));
                q.erase(tmp);
                dists[x][y] = d;

                tmp.first = d;
                q.insert(tmp);
            }
        }
    }

    return dists[destination[0]][destination[1]] == INT_MAX ? -1 : dists[destination[0]][destination[1]];
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,0,1,0,0},
                                     {0,0,0,0,0},
                                     {0,0,0,1,0},
                                     {1,1,0,1,1},
                                     {0,0,0,0,0}};
    vector<int> start{atoi(argv[1]), atoi(argv[2])}, end{atoi(argv[3]), atoi(argv[4])};

    cout << shortestDistance(test_case, start, end) << endl;

    return 0;
}
