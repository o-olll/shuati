#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
    unordered_map<int,int> edges;
    for (auto& row : wall) {
        int d = 0;
        for (int i=0; i<row.size()-1; ++i) {
            d += row[i];
            ++edges[d];
        }
    }
    int res = 0;
    for (auto& p : edges) {
        res = max(res, p.second);
    }
    return wall.size() - res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,2,2,1},
                                     {3,1,2},
                                     {1,3,2},
                                     {2,4},
                                     {3,1,2},
                                     {1,3,1,1}};
    cout << leastBricks(test_case) << endl;

    return 0;
}
