#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

int visit(TreeNode* root, int& diameter)
{
    if (root == NULL)
        return 0;
    int left = visit(root->left, diameter);
    int right = visit(root->right, diameter);

    diameter = max(diameter, left+right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    int res = 0;
    visit(root, res);
    return res;
}

int main(int argc, char** argv)
{
    TreeNode* root;
    if (argc == 1)
        root = deserialize("5,3,6,2,4,/,7");
    else
        root = deserialize(argv[1]);

    string strTree = serialize(root);
    cout << strTree << endl;

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}
