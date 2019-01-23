#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int countCornerRectangles(vector<vector<int>>& grid)
{
    int m=grid.size(), n=grid[0].size(), res=0, count=0;

    for (int i=0,j,k; i<m; ++i) {
        for (j=i+1; j<m; ++j) {
            count = 0;
            for (k=0; k<n; ++k) {
                if (grid[i][k]==1 && grid[j][k]==1)
                    ++count;
            }
            res += count*(count-1)/2;
        }
    }

    return res;

}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,1,1,0},
                             {1,1,1,1},
                             {1,1,1,1},
                             {1,1,0,1}};
    cout << countCornerRectangles(test_case);

    return 0;
}
