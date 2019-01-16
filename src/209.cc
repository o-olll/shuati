#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    int l = 0, res = INT_MAX;
    long sum = 0;

    for (int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        while (sum>=s && l<=i) {
            res = min(res, i-l+1);
            sum -= nums[l++];
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {2,3,1,2,4,3};
    cout << minSubArrayLen(atoi(argv[1]), test_case);

    return 0;
}
