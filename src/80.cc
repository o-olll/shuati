#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int i = 0;

    for (auto n : nums) {
        if (i < 2 || n > nums[i-2]) {
            nums[i++] = n;
        }
    }

    return i;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1,2,2,2,2,2,3};
    cout << removeDuplicates(test_case);

    return 0;
}
