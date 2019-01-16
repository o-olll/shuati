#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = _root;
        for (char c : word) {
            if (node->nexts[c-'a'] == NULL)
                node->nexts[c-'a'] = new TrieNode();
            node = node->nexts[c-'a'];
        }
        node->word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = _root;
        for (char c : word) {
            if (node->nexts[c-'a'] == NULL)
                return false;
            node = node->nexts[c-'a'];
        }
        return !node->word.empty();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = _root;
        for (char c : prefix) {
            if (node->nexts[c-'a'] == NULL)
                return false;
            node = node->nexts[c-'a'];
        }
        return true;
    }

private:
    struct TrieNode {
        string word;
        vector<TrieNode*> nexts;
        TrieNode():nexts(26, NULL) {}
    };

    TrieNode* _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, char** argv)
{
    vector<int> test_case = {};

    return 0;
}
