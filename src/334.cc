#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool increasingTriplet(vector<int>& nums)
{
    vector<int> triplet(2, INT_MAX);
    int i;

    for (int n : nums) {
        for (i=0; i<2 && n>triplet[i]; ++i);
        if (i == 2)
            return true;
        triplet[i] = n;
    }

    return false;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {5,2,3,2,4};
    cout << boolalpha << increasingTriplet(test_case);
    return 0;
}
