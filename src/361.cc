#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maxKilledEnemies(vector<string>& grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    int i, j, row, res = 0;
    vector<int> cols(grid[0].size());

    for (i=0; i<grid.size(); ++i) {
        for (j=0; j<grid[0].size(); ++j) {
            // update row count
            if (j==0 || grid[i][j-1]=='W') {
                row = 0;
                for (int k=j; k<grid[0].size() && grid[i][k]!='W'; ++k)
                    row += grid[i][k] == 'E' ? 1 : 0;
            }

            // update col counts
            if (i==0 || grid[i-1][j]=='W') {
                for (int k=i; k<grid.size() && grid[k][j]!='W'; ++k)
                    cols[j] += grid[k][j] == 'E' ? 1 : 0;
            }

            if (grid[i][j] == '0') {
                res = max(res, row+cols[j]);
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"0EWE",
                                "E0WE",
                                "0WE0",
                                "EWE0"};

    cout << maxKilledEnemies(test_case) << endl;

    return 0;
}
