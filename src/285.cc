#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
    TreeNode* res = NULL;
    while (root) {
        if (p->val < root->val) {
            res = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
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

    TreeNode* p = new TreeNode(6);
    TreeNode* res = inorderSuccessor(root, p);
    cout << res->val << endl;
    return 0;
}
