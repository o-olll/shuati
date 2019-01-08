#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k)
{
    int res=0, sum=0;
    unordered_map<int, int> pos{{0,-1}};

    for (int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        if (!pos.count(sum))
            pos[sum] = i;
        auto it = pos.find(sum-k);
        if (it != pos.end()) {
            res = max(res, i-it->second);
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1,-1,5,-3,0};
    cout << maxSubArrayLen(test_case, 3);
    return 0;
}
