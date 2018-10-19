#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void dfs(int src, int len, const int m, const int n, vector<vector<int>>& jumps, vector<bool>& visited, int& res);

int count(int m, int n, int used, int i1, int j1) {
    int res = m <= 0;
    if (!n) return 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int I = i1 + i, J = j1 + j, used2 = used | (1 << (i * 3 + j));
            if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I / 2 * 3 + J / 2)))) {
                res += count(m - 1, n - 1, used2, i, j);
            }
        }
    }
    return res;
}

int test(int m, int n) {
    return count(m, n, 0, 1, 1);
}

int numberOfPatterns(int m, int n)
{
    vector<vector<int>> jumps(10, vector<int>(10, -1));
    vector<bool> visited(10, false);
    int n1, n2, n5;

    n1 = n2 = n5 = 0;

    jumps[1][3] = jumps[3][1] = 2;
    jumps[4][6] = jumps[6][4] = 5;
    jumps[7][9] = jumps[9][7] = 8;
    jumps[1][7] = jumps[7][1] = 4;
    jumps[2][8] = jumps[8][2] = 5;
    jumps[3][9] = jumps[9][3] = 6;
    jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;

    cout << endl;
    dfs(1, 1, m, n, jumps, visited, n1);
    dfs(2, 1, m, n, jumps, visited, n2);
    dfs(5, 1, m, n, jumps, visited, n5);

    return n1*4 + n2*4 + n5;
}

void dfs(int src, int len, const int m, const int n, vector<vector<int>>& jumps, vector<bool>& visited, int& res)
{
    if (visited[src] || len > n)
        return;
    if (len >= m)
        ++res;

    visited[src] = true;

    for (int i=1; i<=9; ++i) {
        if (i==src || (jumps[src][i]!=-1 && !visited[jumps[src][i]]))
            continue;
        dfs(i, len+1, m, n, jumps, visited, res);
    }

    visited[src] = false;
}

int main(int argc, char** argv)
{
    for (int i=1; i<10; ++i) {
        for (int j=i; j<10; ++j) {
            printf("%d %d: ", i, j);
            int res = numberOfPatterns(i, j);
            int testRes = test(i, j);
            printf("%d %d\n", res, testRes);
            if (res != testRes)
                cout << "****** Not equal ******" << endl;
        }
    }

    return 0;
}
