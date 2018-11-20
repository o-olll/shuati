#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include "utils.h"

using namespace std;

string normalize(string& s)
{
    if (s.empty())
        return s;

    string res(s);
    int shift = s[0] - 'a';

    for (char& c : res) {
        c = (c-'a'+26-shift)%26 + 'a';
    }

    return res;
}

vector<vector<string>> groupStrings(vector<string>& strings)
{
    unordered_map<string,multiset<string>> m;
    vector<vector<string>> res;

    for (string& s : strings) {
        m[normalize(s)].insert(s);
    }

    for (auto& p : m) {
        res.emplace_back();
        for (auto& s : p.second) {
            res.back().push_back(s);
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z", "", "", "abc"};

    vector<vector<string>> res = groupStrings(test_case);

    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
