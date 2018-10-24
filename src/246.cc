#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool isStrobogrammatic(string num)
{
    int l, r;

    l = 0;
    r = num.size() - 1;

    while (l <= r) {
        switch (num[l]) {
            case '0':
            case '1':
            case '8':
                if (num[r] != num[l])
                    return false;
                break;
            case '6':
                if (num[r] != '9')
                    return false;
                break;
            case '9':
                if (num[r] != '6')
                    return false;
                break;
            default:
                return false;
        }
        ++l;
        --r;
    }

    return true;
}

int main(int argc, char** argv)
{
    cout << boolalpha << isStrobogrammatic(argv[1]) << endl;
    return 0;
}
