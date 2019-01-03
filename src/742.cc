#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

pair<int,pair<int,bool>> findImp(TreeNode* root, int k, int& shortest);

int findClosestLeaf(TreeNode* root, int k)
{
    int shortest = INT_MAX;
    findImp(root, k, shortest);
    return shortest;
}

pair<int,pair<int,bool>> findImp(TreeNode* root, int k, int& shortest)
{
    pair<int,pair<int,bool>> res{INT_MAX,{0,false}}, l=res, r=res;

    if (root->left==NULL && root->right==NULL) {
        res.first = 0;
    } else {
        if (root->left != NULL) {
            l = findImp(root->left, k, shortest);
        }
        if (root->right != NULL) {
            r = findImp(root->right, k, shortest);
        }
        res.first = min(l.first, r.first) + 1;
    }

    if (root->val == k) {
        res.second.first = 0;
        res.second.second = true;
        shortest = min(shortest, res.first);
    } else {
        if (l.second.second && root->right!=NULL) {
            res.second.first = l.second.first + 1;
            shortest = min(shortest, l.second.first+r.first+2);
        } else if (r.second.second && root->left!=NULL) {
            res.second.first = r.second.first + 1;
            shortest = min(shortest, r.second.first+l.first+2);
        }
        res.second.second = l.second.second || r.second.second;
    }

    printf("key=%d res=[%d %d %d] shortest=%d\n", root->val, res.first, res.second.first, res.second.second, shortest);
    return res;
}

int main(int argc, char** argv)
{
    TreeNode* root;
    if (argc == 1)
        root = deserialize("5,3,6,2,4,/,7,1,/,/,/,/,/,0,/,-1");
    else
        root = deserialize(argv[1]);

    string strTree = serialize(root);
    cout << strTree << endl;

    cout << findClosestLeaf(root, 2) << endl;
    return 0;
}
