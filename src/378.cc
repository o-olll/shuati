#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int getNumberOfLE(vector<vector<int>>& matrix, int m)
{
    int r, c, res;

    r = matrix.size()-1;
    c = 0;
    res = 0;

    while (r>=0 && c<matrix[0].size()) {
        if (matrix[r][c] <= m) {
            res += r+1;
            ++c;
        } else {
            --r;
        }
    }

    return res;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
    int n = matrix.size(), l, r, m, le;

    l = matrix[0][0];
    r = matrix[n-1][n-1];

    while (l < r) {
        m = l + (r-l)/2;
        le = getNumberOfLE(matrix, m);
        if (le < k) {
            l = m+1;
        } else {
            r = m;
        }
    }

    return l;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{1,5,11},
                                     {8,9,13},
                                     {10,12,15}};

    cout << kthSmallest(test_case, 6) << endl;

    return 0;
}
