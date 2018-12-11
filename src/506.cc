#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<string> findRelativeRanks(vector<int>& nums)
{
    map<int,int,std::greater<int>> m;
    vector<string> res(nums.size());
    int i=1;

    for (int i=0; i<nums.size(); ++i) {
        m[nums[i]] = i;
    }

    for (const auto& p : m) {
        if (i == 1) {
            res[p.second] = "Gold Medal";
        } else if (i == 2) {
            res[p.second] = "Silver Medal";
        } else if (i == 3) {
            res[p.second] = "Brown Medal";
        } else {
            res[p.second] = to_string(i);
        }
        ++i;
    }
    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {4,5,6,1,2,3};
    auto res = findRelativeRanks(test_case);
    utils::printContainer(res.begin(), res.end());
    return 0;
}
