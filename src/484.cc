#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int NF, F, res;

    NF = F = res = 0;

    for (int n : nums) {
        if (n == 0) {
            F = NF + 1;
            NF = 0;
        } else {
            ++NF;
            ++F;
        }
        res = max(res, F);
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {0};

    cout << findMaxConsecutiveOnes(test_case) << endl;

    return 0;
}
