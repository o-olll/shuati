#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void wiggleSort(vector<int> &nums)
{
    for (int i=0; i<nums.size()-1; ++i) {
        if ((i%2==0 && nums[i]>nums[i+1]) ||
            (i%2==1 && nums[i]<nums[i+1]))
            swap(nums[i], nums[i+1]);
    }
}

int main(int argc, char** argv)
{
    vector<int> test_case = {9,8,7,6,5,4,3,2,1};

    wiggleSort(test_case);
    utils::printContainer(test_case.begin(), test_case.end());

    return 0;
}
