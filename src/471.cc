#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string encode(string s)
{
    if (s.size() < 5) {
        return s;
    }

    int len, l, r, k, n;
    vector<vector<string>> dp(s.size(), vector<string>(s.size()));

    n = s.size();

    for (len=1; len<=n; ++len) {
        for (l=0; l+len-1<n; ++l) {
            r = l+len-1;
            dp[l][r] = s.substr(l, len);

            string t, replace;
            int pos;
            t = s.substr(l, len);
            pos = (t+t).find(t, 1);
            if (pos < t.size()) {
                replace = to_string(t.size()/pos) + "[" + dp[l][l+pos-1] + "]";
                if (replace.size() < dp[l][r].size())
                    dp[l][r] = replace;
                continue;
            }

            for (k=l; k<r; ++k) {
                if (dp[l][k].size() + dp[k+1][r].size() < dp[l][r].size())
                    dp[l][r] = dp[l][k] + dp[k+1][r];
            }
        }
    }

    return dp[0][n-1];
}

int main(int argc, char** argv)
{
    string test_case = string(argv[1]);

    cout << encode(test_case) << endl;

    return 0;
}
