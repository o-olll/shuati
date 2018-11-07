#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        _root = new SegTreeNode();
        _max = 0;
    }

    int book(int start, int end) {
        _max = max(_max, add(start, end, _root));
        return _max;
    }

private:
    struct SegTreeNode {
        int l;
        int m;
        int r;
        int count;
        SegTreeNode* left;
        SegTreeNode* right;
        SegTreeNode():
            SegTreeNode(0, INT_MAX, 0) {}
        SegTreeNode(int start, int end, int c):
            l(start), m(-1), r(end), count(c),
            left(NULL), right(NULL) {}
    };

    SegTreeNode* _root;
    int _max;

    int add(int start, int end, SegTreeNode* root) {
        if (root==NULL || start>=end)
            return 0;

        if (start==root->l && end==root->r) {
            ++root->count;
        } else if (root->m == -1) {
            if (start == root->l) {
                root->m = end;
            } else {
                root->m = start;
            }
            root->left = new SegTreeNode(root->l, root->m, root->count);
            root->right = new SegTreeNode(root->m, root->r, root->count);
        }

        return max (max(add(start, min(root->m, end), root->left),
                        add(max(start, root->m), end, root->right)),
                    root->count);
    }
};


int main(int argc, char** argv)
{
    int start, end;
    MyCalendarThree calendar;

    while (cin >> start >> end && start>=0 && end>=0) {
        cout << calendar.book(start, end) << endl;
    }

    return 0;
}
