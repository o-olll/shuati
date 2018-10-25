#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> nexts;
};

string abbr(string s, int pfx=1)
{
    if (s.size()-pfx-1 < 2)
        return s;
    return s.substr(0,pfx) + to_string(s.size()-1-pfx) + s.substr(s.size()-1, 1);
}

TrieNode* buildTrie(vector<string>& strs)
{
    TrieNode* root = new TrieNode();

    for (string& s : strs) {
        TrieNode* node = root;
        for (char c : s) {
            if (node->nexts[c] == NULL)
                node->nexts[c] = new TrieNode;
            node = node->nexts[c];
        }
    }

    return root;
}

void findLongestCommonPfx(TrieNode* root, int level, int& res)
{
    if (root->nexts.empty())
        return;
    if (root->nexts.size() > 1)
        res = max(res, level);
    for (auto it=root->nexts.begin(); it!=root->nexts.end(); ++it) {
        findLongestCommonPfx(it->second, level+1, res);
    }
}

vector<string> wordsAbbreviation(vector<string>& dict)
{
    if (dict.empty())
        return vector<string>();

    unordered_map<string, vector<string>> abbrToStr;
    unordered_map<string, string> strToAbbr;
    vector<string> res;

    for (string& word : dict) {
        abbrToStr[abbr(word)].push_back(word);
    }

    for (auto it=abbrToStr.begin(); it!=abbrToStr.end(); ++it) {
        if (it->second.size() == 1) {
            strToAbbr[*(it->second.begin())] = it->first;
        } else {
            int len = 1;
            findLongestCommonPfx(buildTrie(it->second), 1, len);
            for (string& word : it->second) {
                strToAbbr[word] = abbr(word, len);
            }
        }
    }

    for (string& word : dict)
        res.push_back(strToAbbr[word]);

    return res;
}


int main(int argc, char** argv)
{
    vector<string> test_case = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion",
                                "axxxxx", "ayyyyx", "azzzzx"};

    vector<string> res = wordsAbbreviation(test_case);

    utils::printContainer(res.begin(), res.end());

    return 0;
}
