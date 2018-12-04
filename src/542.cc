#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "utils.h"

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return vector<vector<int>>();
    queue<pair<int,int>> q;
    vector<vector<int>> res(matrix.size(), vector<int> (matrix[0].size(), INT_MAX));
    vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    for (int i=0, j; i<matrix.size(); ++i) {
        for (j=0; j<matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                q.emplace(i, j);
                res[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (const auto& dir : dirs) {
            int x = r + dir.first;
            int y = c + dir.second;
            if (x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || res[x][y]!=INT_MAX)
                continue;
            res[x][y] = res[r][c] + 1;
            q.emplace(x, y);
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,1,1},
                                     {1,1,0},
                                     {1,1,1}}, res;

    res = updateMatrix(test_case);
    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
