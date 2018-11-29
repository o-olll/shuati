#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maxA(int N)
{
    if (N < 2)
        return N;

    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=N; ++i) {
        dp[i] = dp[i-1]+1;
        for (int j=3; i-j>0; ++j) {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }

    return dp[N];
}

int main(int argc, char** argv)
{

    return 0;
}
