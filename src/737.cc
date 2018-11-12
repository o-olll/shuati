#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

string getRoot(string word, unordered_map<string,string>& roots)
{
    auto it = roots.find(word);
    if (it == roots.end())
        roots[word] = word;
    while (roots[word] != word) {
        word = roots[word];
    }
    return word;
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs)
{
    if (words1.size() != words2.size())
        return false;

    unordered_map<string,string> roots;

    for (auto& p : pairs) {
        roots[getRoot(p.first, roots)] = roots[getRoot(p.second, roots)];
    }

    for (int i=0; i<words1.size(); ++i) {
        if (words1[i]!=words2[i] && getRoot(words1[i], roots) != getRoot(words2[i], roots))
            return false;
    }

    return true;
}

int main(int argc, char** argv)
{
    vector<string> words1{"greats", "acting", "skills"}, words2{"greats", "drama", "talent"};

    vector<pair<string,string>> dict{{"great", "good"}, {"fine", "good"},
                                     {"acting","performing"}, {"behaving", "moving"}, {"reacting", "moving"}, {"behaving", "drama"}, {"performing", "reacting"},
                                     {"skills","talent"}};

    cout << boolalpha << areSentencesSimilarTwo(words1, words2, dict) << endl;

    return 0;
}
