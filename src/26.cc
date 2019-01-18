#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();
    int len = 1;
    for (int i=1; i<nums.size(); ++i) {
        if (nums[i] != nums[i-1]) {
            nums[len++] = nums[i];
        }
    }
    return len;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1,2,2,3};
    cout << removeDuplicates(test_case);
    return 0;
}
