#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int MOD = 1000000007;
    
int numWays(int steps, int arrLen) {
    if (steps == 0) return 0;
    
    if (arrLen < 2) return arrLen;
    
    arrLen = min(arrLen, steps);
    vector<unsigned> ways(arrLen, 0);
    ways[0] = 1;
    
    for (int s=0; s<steps; ++s) {
        vector<unsigned> newWays(arrLen, 0);
        for (int p=0; p<arrLen; ++p) {
            newWays[p] = (p>0?ways[p-1]:0) + ways[p] + (p<arrLen-1?ways[p+1]:0);
            newWays[p] %= MOD;
        }
        ways.swap(newWays);
    }
    
    return ways[0];
}

int main(int argc, char** argv)
{
    cout << numWays(1123, 23456) << endl;

    return 0;
}
