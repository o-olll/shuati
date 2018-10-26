#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

double E = 1e-5;

double findMaxAverage(vector<int>& nums, int k)
{
    double left, right, mid, currSum, prevSum, minPrevSum;
    int i;

    left = *min_element(nums.begin(), nums.end());
    right = *max_element(nums.begin(), nums.end());

    cout.precision(10);

    while (right-left > E) {
        mid = left + (right-left)/2;

        cout << "Current mid: " << mid << endl;

        // mid is target average
        // find a subarray which average is above mid

        currSum = prevSum = minPrevSum = 0.0;

        for (i=0; i<nums.size(); ++i) {
            currSum += nums[i] - mid;

            if (i >= k) {
                prevSum += nums[i-k] - mid;
                minPrevSum = min(minPrevSum, prevSum);
            }

            if (i >= k-1) {
                if (currSum - minPrevSum > 0)
                    break;
            }
        }

        // if found a subarray which average is above mid
        // then make target average higher
        if (i < nums.size())
            left = mid;
        else
            right = mid;
    }

    return left;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {18,19,20};

    cout << findMaxAverage(test_case, atoi(argv[1])) << endl;

    return 0;
}
