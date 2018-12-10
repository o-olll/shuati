#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

int getMinimumDifference(TreeNode* root)
{
    if (root == NULL)
        return 0;
    int res = INT_MAX;
    stack<TreeNode*> st;
    TreeNode* last = NULL;

    while (!st.empty() || root!=NULL) {
        if (root != NULL) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            if (last != NULL) {
                res = min(res, root->val-last->val);
            }
            last = root;
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

    cout << getMinimumDifference(root);
    return 0;
}
