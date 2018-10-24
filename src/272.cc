#include <iostream>
#include <vector>
#include <stack>
#include "utils.h"
#include "tree.h"

using namespace std;

void getNextLowers(stack<TreeNode*>& lowers)
{
    TreeNode* node = lowers.top()->left;
    lowers.pop();

    while (node != NULL) {
        lowers.push(node);
        node = node->right;
    }
}

void getNextHighers(stack<TreeNode*>& highers)
{
    TreeNode* node = highers.top()->right;
    highers.pop();

    while (node != NULL) {
        highers.push(node);
        node = node->left;
    }
}

vector<int> closestKValues(TreeNode* root, double target, int k)
{
    stack<TreeNode*> nextLower, nextHigher;
    vector<int> res;

    // build nextLower and nextHigher
    while (root != NULL) {
        if (root->val <= target) {
            printf("Pushing %d to lower\n", root->val);
            nextLower.push(root);
            root = root->right;
        } else {
            printf("Pushing %d to higher\n", root->val);
            nextHigher.push(root);
            root = root->left;
        }
    }

    // fill res
    while (k-- > 0) {
        if (nextLower.empty() && nextHigher.empty())
            return res;

        if (nextHigher.empty() || target-nextLower.top()->val <= nextHigher.top()->val-target) {
            res.push_back(nextLower.top()->val);
            getNextLowers(nextLower);
        } else {
            res.push_back(nextHigher.top()->val);
            getNextHighers(nextHigher);
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

    vector<int> res = closestKValues(root, atof(argv[2]), atoi(argv[3]));

    cout << "Res: ";
    utils::printContainer(res.begin(), res.end());
    cout << endl;

    return 0;
}
