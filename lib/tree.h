#include <iostream>
#include <vector>
#include <string>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

void printInOrder(TreeNode* root);
void printPreOrder(TreeNode* root);

TreeNode* buildTreePreIn(std::vector<int>& pre, std::vector<int>& in);
TreeNode* findNode(TreeNode* root, int target);

std::string serialize(TreeNode* root);
TreeNode* deserialize(std::string s);

namespace std
{
    struct TrieNode {
        string word;
        vector<TrieNode*> links;
        TrieNode() : links(26, NULL) {}
        TrieNode(const string& w) : word(w), links(26, NULL){}
    };

    class Trie {
    public:
        Trie();
        void insert(string word);
        bool search(string word);
        bool startsWith(string prefix);

    private:
        TrieNode* _root;
    };


    template <class T>
    class bst {
    public:
        struct Node {
            T val;
            Node* left;
            Node* right;

            Node(T& v): val(v), left(NULL), right(NULL) {}
        };

        Node* insert(int val);

        bst(): _root(NULL) {}
    private:
        Node* _root;
    };
    /*
    template class<T>
    bst<T>::Node* bst::insert(T& val)
    {
        if (_root == nullptr) {
            _root = new bst::Node(val);
            return _root.;
        }

        bst::Node* last = _root., *current = _root;
        while (current != NULL) {
            last = current;
            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (val < last->val) {
            last->left = new bst::Node*(val);
            current = last->left;
        } else {
            last->right = new bst::Node*(val);
            current = last->right;
        }

        return current;
    }
    */
} // namespace std
