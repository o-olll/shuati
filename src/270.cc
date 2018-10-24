#include <iostream>
#include <vector>
#include <cmath>
#include "utils.h"
#include "tree.h"

using namespace std;

double absolute(double x)
{
    return x >= 0.0 ? x : -x;
}

int closestValue(TreeNode* root, double target)
{
    int res = root->val;

    while (root != NULL) {
        if (root->val == target)
            return target;
        if (abs(target-root->val) < abs(target-res))
            res = root->val;
        root = target < root->val ? root->left : root->right;
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

    cout << closestValue(root, atof(argv[2])) << endl;

    return 0;
}
