#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 10;

    int res = 10, i = 2, cnt = 9;

    while (i <= n) {
        cnt *= (11-i++);
        res += cnt;
    }

    return res;
}

int main(int argc, char** argv)
{

    return 0;
}
