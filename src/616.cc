#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string addBoldTag(string s, vector<string>& dict)
{
    vector<bool> bold(s.size(), false);
    string res;
    int i;

    for (auto& word : dict) {
        size_t pos = s.find(word);;
        while (pos != string::npos) {
            for (int i=0; i<word.size(); ++i)
                bold[pos+i] = true;
            pos = s.find(word, pos+1);
        }
    }

    for (i=0; i<s.size(); ++i) {
        if (bold[i] && (i==0 || !bold[i-1])) {
            res.append("<br>");
        } else if (!bold[i] && i!=0 && bold[i-1]) {
            res.append("</br>");
        }
        res.push_back(s[i]);
    }

    if (i>0 && bold[i-1])
        res.append("</br>");

    return res;
}

int main(int argc, char** argv)
{
    vector<string> dict = {"aaa","aab","bc", "cc", "x"};

    cout << addBoldTag(argv[1], dict) << endl;

    return 0;
}
