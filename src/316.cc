#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> counts(s.size(), 0);
    vector<bool> used(s.size(), false);
    string res;

    for (char c : s) {
        ++counts[c-'a'];
    }

    for (char c : s) {
        --counts[c-'a'];

        if (used[c-'a'])
            continue;

        while (!res.empty() && c<res.back() && counts[res.back()-'a']>0) {
            used[res.back()-'a'] = false;
            res.pop_back();
        }
        res.push_back(c);
        used[c-'a'] = true;
    }

    return res;
}

int main(int argc, char** argv)
{

    cout << removeDuplicateLetters(argv[1]) << endl;
    return 0;
}
