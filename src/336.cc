#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

bool isPalindrome(string s) {
    int l, r;
    l = 0;
    r = s.size()-1;
    while (l < r && s[l] == s[r]) {
        ++l;
        --r;
    }
    return l >= r;
}

vector<vector<int>> palindromePairs(vector<string>& words)
{
    unordered_map<string, int> wordMap;
    vector<vector<int>> res;

    for (int i=0; i<words.size(); ++i) {
        wordMap[words[i]] = i;
    }

    for (int i=0; i<words.size(); ++i) {
        string revWord = words[i];
        reverse(revWord.begin(), revWord.end());

        // add left
        for (int l=revWord.size(); l>=0; --l) {
            if (isPalindrome(words[i].substr(0, revWord.size()-l))) {
                auto it = wordMap.find(revWord.substr(0, l));
                if (it!=wordMap.end() && it->second!=i)
                    res.push_back({it->second, i});
            }
        }

        // add right
        // starting from size-1 to avoid duplicates
        // e.g. "abc" and "cba", result cannot be {0,1} {1,0} {0,1} {1,0}
        for (int l=revWord.size()-1; l>=0; --l) {
            if (isPalindrome(revWord.substr(0, revWord.size()-l))) {
                auto it = wordMap.find(revWord.substr(revWord.size()-l));
                if (it!=wordMap.end() && it->second!=i)
                    res.push_back({i, it->second});
            }
        }
    }

    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"abcd", "dcba", "lls", "s", "sssll"};

    vector<vector<int>> res = palindromePairs(test_case);

    for (auto& v : res) {
        printf("(%d %d) ", v[0], v[1]);
    }
    cout << endl;

    return 0;
}
