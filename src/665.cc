#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool checkPossibility(vector<int>& nums)
{
    bool changed = false;
    for (int i=0; i<nums.size()-1; ++i) {
        if (nums[i] > nums[i+1]) {
            if (changed)
                return false;
            changed = true;
            if (i>0 && nums[i]==nums[i-1])
                nums[i+1] = nums[i];
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {3,3,2,2};
    cout << boolalpha << checkPossibility(test_case);

    return 0;
}
