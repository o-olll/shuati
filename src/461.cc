#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include "utils.h"

using namespace std;

int hammingDistance(int x, int y)
{
    return bitset<32> (x^y).count();
}

int main(int argc, char** argv)
{
    cout << hammingDistance(atoi(argv[1]), atoi(argv[2]));

    return 0;
}
