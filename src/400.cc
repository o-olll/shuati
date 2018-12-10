#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int findNthDigit(int n)
{
    long level, count, start;

    level = 1;
    count = 9;
    start = 1;

    while (n > level*count) {
        n -= level*count;
        ++level;
        count *= 10;
        start *= 10;
    }

    start += (--n)/level;
    return to_string(start)[n%level] - '0';
}

int main(int argc, char** argv)
{

    return 0;
}
