#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

void longestImp(TreeNode* root, int last, int len, int& res);

int longestConsecutive(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int res = 1;
    longestImp(root->left, root->val, 1, res);
    longestImp(root->right, root->val, 1, res);

    return res;
}

void longestImp(TreeNode* root, int last, int len, int& res)
{
    if (root == NULL)
        return;

    if (root->val == last + 1) {
        ++len;
        res = max(res, len);
    } else {
        len = 1;
    }

    longestImp(root->left, root->val, len, res);
    longestImp(root->right, root->val, len, res);
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
    cout << longestConsecutive(root) << endl;
    return 0;
}
