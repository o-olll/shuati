#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findLonelyPixel(vector<vector<char>>& picture)
{
    if (picture.empty() || picture[0].empty())
        return 0;
    int m = picture.size(), n = picture[0].size(), res = 0;
    vector<int> rows(m, 0), cols(n, 0);

    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (picture[i][j] == 'B') {
                ++rows[i];
                ++cols[j];
            }
        }
    }

    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (picture[i][j] == 'B') {
                if (rows[i] == 1 && cols[j] == 1) {
                    ++res;
                }
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
