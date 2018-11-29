#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

pair<int,int> visit(TreeNode* root, int& longest)
{
    if (root == NULL)
        return make_pair(0, 0);

    pair<int,int> left = visit(root->left, longest);
    pair<int,int> right = visit(root->right, longest);

    // res.first: child to parent increasing
    // len.first: left to right increasing

    pair<int,int> res = {1, 1}, len = {0, 0};

    if (root->left != NULL) {
        if (root->left->val+1 == root->val) {
            len.first += left.first;
            res.first = max(res.first, left.first+1);
        } else if (root->left->val-1 == root->val) {
            len.second += left.second;
            res.second = max(res.second, left.second+1);
        }
    }

    if (root->right != NULL) {
        if (root->right->val+1 == root->val) {
            len.second += right.first;
            res.first = max(res.first, right.first+1);
        } else if (root->right->val-1 == root->val) {
            len.first += right.second;
            res.second = max(res.second, right.second+1);
        }
    }

    longest = max(longest, max(len.first+1, len.second+1));

    // printf("node=%d res=(%d %d) longest=%d\n", root->val, res.first, res.second, longest);

    return res;
}

int longestConsecutive(TreeNode* root) {
    int res = 0;
    visit(root, res);
    return res;
}

int main(int argc, char** argv)
{
    TreeNode* root;
    if (argc == 1)
        root = deserialize("5,6,4,5,8,5,3,4");
    else
        root = deserialize(argv[1]);

    string strTree = serialize(root);
    cout << strTree << endl;

    cout << longestConsecutive(root) << endl;
    return 0;
}
