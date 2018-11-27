#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "utils.h"
#include "tree.h"

using namespace std;

vector<vector<int>> verticalOrder(TreeNode* root)
{
    if (root == NULL)
        return vector<vector<int>>();

    int minX = INT_MAX, maxX = INT_MIN;
    unordered_map<int, vector<TreeNode*>> m;
    queue<pair<TreeNode*,int>> q;
    vector<vector<int>> res;

    q.emplace(root, 0);

    while (!q.empty()) {
        pair<TreeNode*, int> node = q.front();
        q.pop();
        m[node.second].push_back(node.first);
        minX = min(minX, node.second);
        maxX = max(maxX, node.second);

        if (node.first->left != NULL)
            q.emplace(node.first->left, node.second-1);
        if (node.first->right != NULL)
            q.emplace(node.first->right, node.second+1);
    }

    for (int i=minX; i<=maxX; ++i) {
        res.emplace_back();
        for (TreeNode* node : m[i])
            res.back().push_back(node->val);
    }

    return res;
}

int main(int argc, char** argv)
{
    TreeNode* root;
    if (argc == 1)
        root = deserialize("5,2,6,1,3,/,7,/,/,/,4");
    else
        root = deserialize(argv[1]);

    string strTree = serialize(root);
    cout << strTree << endl;

    vector<vector<int>> res = verticalOrder(root);
    for (auto& v : res) {
        utils::printContainer(v.begin(), v.end());
    }

    return 0;
}
