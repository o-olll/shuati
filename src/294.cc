#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool canWin(string s)
{
    for (int i=0; i<s.size()-1; ++i) {
        if (s[i]=='+' && s[i+1]=='+') {
            s[i] = s[i+1] = '-';
            if (!canWin(s))
                return true;
            s[i] = s[i+1] = '+';
        }
    }

    return false;
}

int main(int argc, char** argv)
{
    cout << boolalpha << canWin(argv[1]) << endl;

    return 0;
}
