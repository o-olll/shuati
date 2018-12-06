#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool isPossible(vector<int>& nums)
{
    unordered_map<int,int> freqs, needs;

    for (int num : nums) {
        ++freqs[num];
    }

    for (int num : nums) {
        if (freqs[num] == 0)
            continue;
        if (needs[num]>0) {
            --needs[num];
            ++needs[num+1];
        } else if (freqs[num+1]>0 && freqs[num+2]>0) {
            --freqs[num+1];
            --freqs[num+2];
            ++needs[num+3];
        } else {
            return false;
        }
        --freqs[num];
    }

    return true;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
