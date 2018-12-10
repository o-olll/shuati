#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> res;
    for (int num : nums) {
        num = abs(num);
        if (nums[num-1] > 0) {
            nums[num-1] = -nums[num-1];
        }
    }
    for (int i=0; i<nums.size(); ++i) {
        if (nums[i] > 0)
            res.push_back(i+1);
    }
    return res;
}
int main(int argc, char** argv)
{
    vector<int> test_case = {1,1,2,2,3,3}, res;

    res = findDisappearedNumbers(test_case);
    utils::printContainer(res.begin(), res.end());

    return 0;
}
