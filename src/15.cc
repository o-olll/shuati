#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    if (nums.size() < 3)
        return {};
    vector<vector<int>> res;
    int l, r, s, k;

    sort(nums.begin(), nums.end());

    for (int i=0; i<nums.size()-2; ++i) {
        l = i+1;
        r = nums.size()-1;
        k = -nums[i];
        while (l < r) {
            s = nums[l] + nums[r];
            if (s == k) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (r>l && nums[r]==nums[r-1]) --r;
                while (l<r && nums[l]==nums[l+1]) ++l;
                --r;
                ++l;
            } else if (s > k) {
                --r;
            } else {
                ++l;
            }
        }
        while (i<nums.size()-3 && nums[i]==nums[i+1])
            ++i;
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {-1};
    auto res = threeSum(test_case);

    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
