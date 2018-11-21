#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int longestLine(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty())
        return 0;

    int i, j, n, res = 0;

    // horizontal
    for (i=0; i<M.size(); ++i) {
        for (j=0,n=0; j<M[i].size(); ++j) {
            if (M[i][j] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    // vertical
    for (j=0; j<M[0].size(); ++j) {
        for (i=0,n=0; i<M.size(); ++i) {
            if (M[i][j] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    // diagnal lower half
    for (i=0; i<M.size(); ++i) {
        for (j=0,n=0; j<M[0].size() && i+j<M.size(); ++j) {
            if (M[j+i][j] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    // diagnal higher half
    for (j=0; j<M[0].size(); ++j) {
        for (i=0,n=0; i<M.size() && i+j<M[0].size(); ++i) {
            if (M[i][i+j] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    // anti diagnal lower half
    for (i=0; i<M.size(); ++i) {
        for (j=M[0].size()-1,n=0; j>=0 && M[0].size()-1-j+i<M.size(); --j) {
            if (M[M[0].size()-1-j+i][j] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    // anti diagnal lower half
    for (j=M[0].size()-1; j>0; --j) {
        for (i=0,n=0; i<M.size() && j>=i; ++i) {
            if (M[i][j-i] == 0)
                n = 0;
            else {
                ++n;
                res = max(res, n);
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<vector<int>> test_case = {{0,1,0,1},
                                     {0,0,1,0},
                                     {0,0,1,0},
                                     {0,1,0,0},
                                     {1,1,0,0}};

    cout << longestLine(test_case) << endl;

    return 0;
}
