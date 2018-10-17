#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool validWordAbbreviation(string word, string abbr)
{
    if (word.empty() || abbr.empty())
        return false;

    int i, j, n;

    for (i=0, j=0, n=0; j<abbr.size() && i<word.size(); ++j) {
        if (isalpha(abbr[j])) {
            if (n != 0) {
                i += n;
                n = 0;
            }
            if (word[i++] != abbr[j])
                return false;
        } else {
            n = n*10 + abbr[j] - '0';
        }
    }

    if (n != 0) {
        i += n;
    }

    return j==abbr.size() && i==word.size();
}

int main(int argc, char** argv)
{
    string word(argv[1]), abbr(argv[2]);

    cout << boolalpha << validWordAbbreviation(word, abbr) << endl;

    return 0;
}
