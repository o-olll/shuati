#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "utils.h"

using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    vector<int> sorted;
    auto endIt = sorted.end();

    for (int n : nums) {
        auto it = lower_bound(sorted.begin(), endIt, n);
        if (it == endIt) {
            sorted.push_back(n);
            endIt = sorted.end();
        } else {
            *it = n;
        }
    }

    return endIt - sorted.begin();
}

int main(int argc, char** argv)
{
    vector<int> test_case = {10,9,2,5,3,7,101,18};

    int res = lengthOfLIS(test_case);
    cout << endl << res;
    return 0;
}
