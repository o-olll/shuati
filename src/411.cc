#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void getAbbreviations(string target, int starting, vector<pair<int,string>>& res)
{
    int i, j;

    for (i=starting; i<target.size(); ++i) {
        for (j=i+1; j<=target.size(); ++j) {
            string abbr = target.substr(0, i) + to_string(j-i) + target.substr(j);
            res.emplace_back(i+1+target.size()-j, abbr);
            getAbbreviations(abbr, i+1+to_string(j-i).size(), res);
        }
    }
}

bool isValidAbbr(string& word, string& abbr)
{
    int i, j, n=0; // i: index of word, j: index of abbr
    for (i=0,j=0; i<word.size() && j<abbr.size(); ++j) {
        if (isalpha(abbr[j])) {
            if (n != 0) {
                i += n;
                n = 0;
            }
            if (word[i++] != abbr[j])
                return false;
        } else {
            n = n*10 + abbr[j]-'0';
        }
    }

    if (n != 0)
        i += n;

    return i==word.size() && j==abbr.size();
}

string minAbbreviation(string target, vector<string>& dictionary)
{
    vector<pair<int,string>> abbrs;
    int i;

    abbrs.emplace_back(target.size(), target);
    getAbbreviations(target, 0, abbrs);
    sort(abbrs.begin(), abbrs.end());

    for (auto& p : abbrs) {
        string& abbr = p.second;
        for (i=0; i<dictionary.size(); ++i) {
            if (target.size() == dictionary[i].size() && isValidAbbr(dictionary[i], abbr))
                break;
        }
        if (i == dictionary.size())
            return abbr;
    }

    return "";
}

int main(int argc, char** argv)
{
    vector<string> dict = {"plain", "amber", "blade"};

    cout << minAbbreviation(argv[1], dict) << endl;

    return 0;
}
