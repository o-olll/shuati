#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

void mark(string& s, string& word, vector<bool>& bolds)
{
    int p = s.find(word);
    while (p != string::npos) {
        for (int i=0; i<word.size(); ++i) {
            bolds[p+i] = true;
        }
        p = s.find(word, p+1);
    }
}

string boldWords(vector<string>& words, string S)
{
    vector<bool> bolds(S.size(), false);
    for (string& word : words) {
        mark(S, word, bolds);
    }
    string res;
    for (int i=0; i<S.size(); ++i) {
        if (bolds[i]) {
            if (i==0 || !bolds[i-1])
                res.append("<br>");
        }
        res.push_back(S[i]);
        if (bolds[i]) {
            if (i==S.size()-1 || !bolds[i+1])
                res.append("</br>");
        }
    }
    return res;
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"abc", "bcd", "mm"};
    cout << boldWords(test_case, argv[1]);

    return 0;
}
