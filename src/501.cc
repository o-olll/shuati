#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

vector<int> findMode(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> res;
    int last = INT_MAX, current = 0, most = 0;
    while (!st.empty() || root!=NULL) {
        if (root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            root = st.top();
            st.pop();
            if (root->val == last)
                ++current;
            else
                current = 1;
            if (current == most) {
                res.push_back(root->val);
            } else if (current > most) {
                res.clear();
                res.push_back(root->val);
                most = current;
            }
            last = root->val;
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

    return 0;
}
