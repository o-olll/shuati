#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

void visit(TreeNode* root, string current, vector<string>& res)
{
    if (!current.empty())
        current.append("->");
    current.append(to_string(root->val));
    if (root->left==NULL && root->right==NULL) {
        res.push_back(current);
    }
    if (root->left != NULL)
        visit(root->left, current, res);
    if (root->right != NULL)
        visit(root->right, current, res);
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> res;
    if (root == NULL)
        return res;
    visit(root, "", res);
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

    return 0;
}
