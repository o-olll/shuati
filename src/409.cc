#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

int longestPalindrome(string s)
{
    int res = 0;
    unordered_set<char> chars;
    for (char c : s) {
        auto it = chars.find(c);
        if (it == chars.end())
            chars.insert(c);
        else {
            res += 2;
            chars.erase(it);
        }
    }
    return res + !chars.empty();
}

int main(int argc, char** argv)
{
    cout << longestPalindrome(argv[1]) << endl;

    return 0;
}
