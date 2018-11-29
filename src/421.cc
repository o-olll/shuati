#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

int findMaximumXOR(vector<int>& nums)
{
    int mask = 0, res = 0, t;
    unordered_set<int> prefixes;

    for (int i=31; i>=0; --i) {
        prefixes.clear();
        mask |= (1 << i);
        for (int num : nums) {
            prefixes.insert(num & mask);
        }

        t = res | (1 << i);

        for (int prefix : prefixes) {
            if (prefixes.count(t^prefix)) {
                res = t;
                break;
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1,1};

    cout << findMaximumXOR(test_case) << endl;

    return 0;
}
