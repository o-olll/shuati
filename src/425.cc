#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "utils.h"

using namespace std;

struct Trie {
    Trie(): nexts(26, NULL) {}
    vector<string> words;
    vector<Trie*> nexts;
};

Trie* buildTrie(const vector<string>& words);
void buildTrieImp(const string& word, Trie* root);
Trie* findPrefix(Trie* root, const string& word);
void wordSquaresImp(Trie* root, vector<vector<string>>& res,
                    vector<string>& current, int level,
                    const int len, unordered_set<string>& visited);

vector<vector<string>> wordSquares(vector<string>& words)
{
    vector<vector<string>> res;
    if (words.empty() || words[0].empty())
        return res;

    Trie* trie = buildTrie(words);
    vector<string> current;
    unordered_set<string> visited;

    for (string word : words) {
        current.push_back(word);
        visited.insert(word);
        wordSquaresImp(trie, res, current, 1, words[0].size(), visited);
        visited.erase(word);
        current.pop_back();
    }

    return res;
}

Trie* buildTrie(const vector<string>& words)
{
    Trie* root = new Trie();
    for (const string& word : words) {
        buildTrieImp(word, root);
    }
    return root;
}

void buildTrieImp(const string& word, Trie* root)
{
    for (char c : word) {
        if (root->nexts[c-'a'] == NULL)
            root->nexts[c-'a'] = new Trie();
        root = root->nexts[c-'a'];
        root->words.push_back(word);
    }
}

Trie* findPrefix(Trie* root, const string& word)
{
    for (char c : word) {
        if (root == NULL)
            return NULL;
        root=root->nexts[c-'a'];
    }
    return root;
}

void wordSquaresImp(Trie* root, vector<vector<string>>& res,
                    vector<string>& current, int level,
                    const int len, unordered_set<string>& visited)
{
    if (level == len) {
        res.push_back(current);
        return;
    }

    string prefix;
    for (string s : current) {
        prefix.push_back(s[level]);
    }

    Trie* t = findPrefix(root, prefix);
    if (t == NULL)
        return;

    for (string& word : t->words) {
        if (visited.count(word) > 0)
            continue;
        visited.insert(word);
        current.push_back(word);
        wordSquaresImp(root, res, current, level+1, len, visited);
        current.pop_back();
        visited.erase(word);
    }
}

int main(int argc, char** argv)
{
    vector<string> test_case = {"area","lead","wall","lady","ball"};


    vector<vector<string>> res = wordSquares(test_case);

    for (auto& v : res) {
        for (string& s : v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}
