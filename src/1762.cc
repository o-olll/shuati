#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

vector<int> getBuildingsWithOV(const vector<int>& buildings) {
    vector<int> res;
    int highest = -1;

    for (int i=buildings.size()-1; i>=0; --i) {
        if (buildings[i] > highest) {
            res.push_back(i);
            highest = buildings[i];
        }
    }
 
    reverse(res.begin(), res.end());

    return res;
}


int main(int argc, char** argv)
{
    vector<int> test_case = {4,2,3,1};

    vector<int> res = getBuildingsWithOV(test_case);
    
    utils::printContainer(res.begin(), res.end());

    return 0;
}
