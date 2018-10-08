#include "tree.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void printInOrderIterative(TreeNode* root) {
    stack<TreeNode*> st;

    while (!st.empty() || root!=NULL) {
        if (root != NULL) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            cout << root->val << " ";
            st.pop();
            root = root->right;
        }
    }

    return;
}

void printInOrderRecursive(TreeNode* root) {
    if (root == NULL)
        return;
    printInOrderRecursive(root->left);
    cout << root->val << " ";
    printInOrderRecursive(root->right);
}

void printInOrder(TreeNode* root) {
    printInOrderIterative(root);
    cout << endl;
}

void printPreOrderRecursive(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    printPreOrderRecursive(root->left);
    printPreOrderRecursive(root->right);
}

void printPreOrder(TreeNode* root) {
    printPreOrderRecursive(root);
    cout << endl;
}

TreeNode* buildTreePreInImp(vector<int>& pre, int& prePos,
                            vector<int>& in, int inStart, int inEnd,
                            unordered_map<int, int>& inMap)
{
    if (inStart > inEnd) {
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[prePos]);
    int i = inMap[pre[prePos]];
    ++prePos;
    root->left = buildTreePreInImp(pre, prePos, in, inStart, i-1, inMap);
    root->right = buildTreePreInImp(pre, prePos, in, i+1, inEnd, inMap);

    return root;
}

TreeNode* buildTreePreIn(vector<int>& pre, vector<int>& in)
{
    unordered_map<int, int> inMap;
    for (int i=0; i<in.size(); ++i) {
        inMap[in[i]] = i;
    }
    int p = 0;
    return buildTreePreInImp(pre, p, in, 0, in.size()-1, inMap);
}

/* Using pre-order to find the target
 * Tree does not have to be a BST
 */
TreeNode* findNode(TreeNode* root, int target)
{
    if (root == NULL) {
        return NULL;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();
        if (root->val == target)
            return root;

        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }

    return NULL;
}

TreeNode* deserializeImpPreOrder(istringstream& iss)
{
    string value;
    if (!getline(iss, value, ',') || value == "/") {
        return NULL;
    }

    TreeNode* node = new TreeNode(stoi(value));
    node->left = deserializeImpPreOrder(iss);
    node->right = deserializeImpPreOrder(iss);

    return node;
}

TreeNode* deserializeImp(istringstream& iss)
{
    string value;
    if (!getline(iss, value, ',') || value == "/") {
        return NULL;
    }

    TreeNode *node, *root;
    queue<TreeNode*> q;
    q.push(new TreeNode(stoi(value)));
    root = q.back();

    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (getline(iss, value, ',') && value != "/") {
            q.push(new TreeNode(stoi(value)));
            node->left = q.back();
        }

        if (getline(iss, value, ',') && value != "/") {
            q.push(new TreeNode(stoi(value)));
            node->right = q.back();
        }
    }

    return root;
}

string serialize(TreeNode* root)
{
    queue<TreeNode*> q;
    int n = root==NULL ? 0 : 1;
    q.push(root);
    ostringstream oss;

    while (!q.empty() && n>0) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            oss << "/,";
        } else {
            --n;
            q.push(node->left);
            q.push(node->right);
            n += (node->left == NULL ? 0 : 1);
            n += (node->right == NULL ? 0 : 1);
            oss << node->val;
            if (n > 0)
                oss << ",";
        }
    }

    //cout << oss.str() << endl;
    return oss.str();
}

TreeNode* deserialize(string s)
{
    if (s.empty()) {
        return NULL;
    }

    istringstream iss(s);
    return deserializeImp(iss);
}

Trie::Trie()
{
    _root = new TrieNode();
}

void Trie::insert(string word)
{
    TrieNode* node = _root;

    for (char c : word) {
        if ((node->links)[c-'a'] == NULL) {
            (node->links)[c-'a'] = new TrieNode();
        }
        node = (node->links)[c-'a'];
    }

    node->word = word;
}

bool Trie::search(string word)
{
    TrieNode* node = _root;

    for (char c : word) {
        node = (node->links)[c-'a'];
        if (node == NULL)
            return false;
    }

    return node->word == word;
}

bool Trie::startsWith(string prefix)
{
    TrieNode* node = _root;

    for (char c : prefix) {
        node = (node->links)[c-'a'];
        if (node == NULL)
            return false;
    }

    return true;
}
