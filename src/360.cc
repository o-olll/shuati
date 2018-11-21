#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int f(int x, int a, int b, int c)
{
    return a*x*x + b*x + c;
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c)
{
    if (a == 0)
        return nums;

    double m = -b/a/2;
    int mp, l, r;
    vector<int> res(nums.size());

    for (mp=0; mp<nums.size() && nums[mp]<m; ++mp);

    l = mp-1;
    r = mp;

    for (int i=0; i<nums.size(); ++i) {
        if (r==nums.size() || (l!=-1 && m+m<nums[l]+nums[r]))
            res[i] = f(nums[l--], a, b, c);
        else
            res[i] = f(nums[r++], a, b, c);
    }

    if (a < 0)
        reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {-20,-19,-18,-17,-15,-13,-11,-9,-8,-7,-6,-5,-3,-1,3,5,8,10,18,19}, res;

    res = sortTransformedArray(test_case, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    utils::printContainer(res.begin(), res.end());

    for (int& i : test_case) {
        i = f(i, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    }
    sort(test_case.begin(), test_case.end());
    utils::printContainer(test_case.begin(), test_case.end());

    return 0;
}
