#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "utils.h"

using namespace std;

vector<pair<int,int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    queue<pair<int,int>> q;
    pair<int,int> node, neighbor;

    maze[start[0]][start[1]] = 2;
    q.emplace(start[0], start[1]);

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (auto& dir : dirs) {
            neighbor = node;
            while (neighbor.first>=0 && neighbor.first<maze.size() && neighbor.second>=0 && neighbor.second<maze[0].size() &&
                   maze[neighbor.first][neighbor.second]!=1) {
                neighbor.first += dir.first;
                neighbor.second += dir.second;
            }
            neighbor.first -= dir.first;
            neighbor.second -= dir.second;
            if (maze[neighbor.first][neighbor.second] == 0) {
                if (neighbor.first==destination[0] && neighbor.second==destination[1])
                    return true;
                maze[neighbor.first][neighbor.second] = 2;
                q.push(neighbor);
                printf("(%d, %d)\n", neighbor.first, neighbor.second);
            }
        }
    }

    return false;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,0,1,0,0},
                                     {0,0,0,0,0},
                                     {0,0,0,1,0},
                                     {1,1,0,1,1},
                                     {0,0,0,0,0}};
    vector<int> start{atoi(argv[1]), atoi(argv[2])}, end{atoi(argv[3]), atoi(argv[4])};

    cout << boolalpha << hasPath(test_case, start, end) << endl;

    return 0;
}
