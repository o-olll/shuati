#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> cheapestJump(vector<int>& A, int B)
{
    vector<int> dp(A.size(), INT_MAX), last(A.size(), -1), len(A.size(), 0), res;

    dp[0] = 0;
    len[0] = 1;

    for (int i=1; i<A.size(); ++i) {
        if (A[i] == -1)
            continue;

        for (int k=min(B, i); k>0; --k) {
            if (A[i-k] != -1 && dp[i-k]+A[i-k] <= dp[i] && len[i] <= len[i-k]) {
                dp[i] = dp[i-k] + A[i-k];
                last[i] = i-k;
                len[i] = len[i-k] + 1;
            }
        }

        printf("%d: dp[i]=%d, last[i]=%d\n", i, dp[i], last[i]);
    }

    if (last.back() == -1)
        return res;

    for (int i=last.size()-1; i!=-1; i=last[i])
        res.push_back(i+1);

    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {6,4,4,0,6}, res;

    res = cheapestJump(test_case, 2);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
