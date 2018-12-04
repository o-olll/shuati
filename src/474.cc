#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int zeros, ones, i, j;

    for (const string& s : strs) {
        for (zeros=0,ones=0,i=0; i<s.size(); ++i) {
            if (s[i] == '0')
                ++zeros;
            else
                ++ones;
        }
        for (i=m; i>=zeros; --i) {
            for (j=n; j>=ones; --j) {
                dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
            }
        }
    }

    return dp[m][n];
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(test_case, 0, 0) << endl;

    return 0;
}
