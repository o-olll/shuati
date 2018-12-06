#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int l, r, m;

    l = 0;
    r = arr.size() - k;

    while (l < r) {
        m = (l+r) / 2;
        if (x-arr[m] > arr[m+k]-x)
            l = m+1;
        else
            r = m;
    }

    return vector<int>(arr.begin()+l, arr.begin()+l+k);
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
