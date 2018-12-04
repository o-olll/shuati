#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "utils.h"

using namespace std;

bool isValidSerialization(string preorder)
{
    if (preorder.empty())
        return true;
    int n = 1;
    istringstream iss(preorder);
    string s;

    while (getline(iss, s, ',')) {
        --n;
        if (n < 0)
            return false;
        if (s != "#")
            n += 2;
    }

    return n == 0;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
