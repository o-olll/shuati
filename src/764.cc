#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
{
    vector<vector<int>> h(N, vector<int>(N,N)), v(N, vector<int>(N,N));
    vector<int> line(N, 0);
    int k, res=0;

    for (auto& v : mines) {
        h[v[0]][v[1]] = 0;
    }

    for (int i=0,j; i<N; ++i) {
        for (j=0,k=0; j<N; ++j) {
            if (h[i][j] > 0) {
                ++k;
                ++line[j];
            } else {
                k = 0;
                line[j] = 0;
            }
            h[i][j] = k;
            v[i][j] = line[j];
        }
    }

    for (int &n : line) n = 0;

    for (int i=N-1,j; i>=0; --i) {
        for (j=N-1,k=0; j>=0; --j) {
            if (h[i][j] > 0) {
                ++k;
                ++line[j];
            } else {
                k = 0;
                line[j] = 0;
            }
            h[i][j] = min(h[i][j], k);
            v[i][j] = min(v[i][j], line[j]);
            res = max(res, min(h[i][j], v[i][j]));
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{4,2},{2,3},{2,1},{1,2}};
    cout << orderOfLargestPlusSign(5, test_case);

    return 0;
}
