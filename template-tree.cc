#include <iostream>
#include <vector>
#include "utils.h"
#include "tree.h"

using namespace std;

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
