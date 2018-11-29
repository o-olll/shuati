#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

void visit(TreeNode* node, bool lb, bool rb, vector<int>& res);

vector<int> boundaryOfBinaryTree(TreeNode* root)
{
    if (root == NULL)
        return {};

    vector<int> res{root->val};
    visit(root->left, true, false, res);
    visit(root->right, false, true, res);

    return res;
}

void visit(TreeNode* node, bool lb, bool rb, vector<int>& res)
{
    if (node == NULL)
        return;

    if (node->left == NULL && node->right == NULL) {
        res.push_back(node->val);
        return;
    }

    if (lb)
        res.push_back(node->val);
    visit(node->left, lb, rb && node->right==NULL, res);
    visit(node->right, lb && node->left==NULL, rb, res);
    if (rb)
        res.push_back(node->val);
}

int main(int argc, char** argv)
{
    TreeNode* root;
    if (argc == 1)
        root = deserialize("1,2,5,/,3,/,/,4,7,/,8,/,9");
    else
        root = deserialize(argv[1]);

    string strTree = serialize(root);
    cout << strTree << endl;

    vector<int> res = boundaryOfBinaryTree(root);
    utils::printContainer(res.begin(), res.end());

    return 0;
}
