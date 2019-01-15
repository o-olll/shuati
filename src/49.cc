#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;

    for (string& str : strs) {
        vector<int> count(26, 0);
        for (char c : str) {
            ++count[c-'a'];
        }
        string s;
        for (int i=0; i<26; ++i) {
            if (count[i] != 0) {
                s.push_back('a'+i);
                s.append(to_string(count[i]));
            }
        }
        m[s].push_back(str);
    }

    for (auto& p : m) {
        res.emplace_back();
        for (string& str : p.second) {
            res.back().push_back(str);
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(test_case);
    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }
    return 0;
}
