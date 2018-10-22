#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string rearrangeString(string str, int k)
{
    string res;
    vector<pair<int, char>> counts(26);

    for (int i=0; i<26; ++i) {
        counts[i].first = 0;
        counts[i].second = 'a' + i;
    }

    for (char c : str) {
        ++counts[c-'a'].first;
    }

    sort(counts.begin(), counts.end());

    vector<string> strs(counts.back().first);

    for (int i=counts.size()-1; i>=0 && counts[i].first>0; --i) {
        for (int j=0; j<counts[i].first; ++j) {
            strs[j].push_back(counts[i].second);
        }
    }

    if (strs.size() > 1 && strs[strs.size()-2].size() < k)
        return "";

    for (string s : strs)
        res.append(s);

    return res;
}

int main(int argc, char** argv)
{
    cout << rearrangeString(argv[1], atoi(argv[2])) << endl;

    return 0;
}
