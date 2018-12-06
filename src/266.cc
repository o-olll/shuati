#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

bool canPermutePalindrome(string s)
{
    unordered_set<char> chars;
    for (char c : s) {
        auto it = chars.find(c);
        if (it == chars.end()) {
            chars.insert(c);
        }
        else {
            chars.erase(it);
        }
    }
    return chars.size() < 2;
}

int main(int argc, char** argv)
{
    cout << boolalpha << canPermutePalindrome(argv[1]) << endl;

    return 0;
}
