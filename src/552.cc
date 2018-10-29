#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int checkRecord(int n)
{
    int M = 1000000007;

    vector<int> t = {0, 3, 8};
    if (n < 3)
        return t[n];

    vector<vector<int>> dp(2, vector<int>(3, 0)), last = {{2,1,1}, {3,1,0}};

    for (int i=3; i<=n; ++i) {
        dp[0][0] = ((last[0][0] + last[0][1]) % M + last[0][2]) % M;
        dp[0][1] = last[0][0];
        dp[0][2] = last[0][1];
        dp[1][0] = ((dp[0][0] + last[1][0]) % M + (last[1][1] + last[1][2]) % M) % M;
        dp[1][1] = last[1][0];
        dp[1][2] = last[1][1];
        last = dp;
    }

    int res = 0;
    for (int i=0; i<2; ++i)
        for (int j=0; j<3; ++j)
            res = (res + dp[i][j]) % M;

    return res;
}

int test(int n) {
    int M = 1000000007;
    vector<int> P(n), L(n), A(n);
    P[0] = 1; L[0] = 1; L[1] = 3;
    A[0] = 1; A[1] = 2; A[2] = 4;
    for (int i = 1; i < n; ++i) {
        P[i] = ((P[i - 1] + L[i - 1]) % M + A[i - 1]) % M;
        if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % M + (A[i - 2] + P[i - 2]) % M) % M;
        if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % M + A[i - 3]) % M;
    }
    return ((A[n - 1] + P[n - 1]) % M + L[n - 1]) % M;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    cout << checkRecord(atoi(argv[1])) << " " << test(atoi(argv[1])) << endl;

    return 0;
}
