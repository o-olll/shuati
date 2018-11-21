#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
#include "list.h"

using namespace std;

ListNode* plusOne(ListNode* head)
{
    ListNode *p, *r;

    p = new ListNode(0);
    p->next = head;
    head = p;

    for (p=head,r=NULL; p!=NULL; p=p->next) {
        if (p->val != 9)
            r = p;
    }

    ++r->val;

    for (p=r->next; p!=NULL; p=p->next)
        p->val = 0;

    if (head->val == 0) {
        r = head->next;
        delete head;
        return r;
    }

    return head;
}

int main(int argc, char** argv)
{
    vector<int> nums{0};

    ListNode* head = generateList(nums.begin(), nums.end());
    printList(head);

    head = plusOne(head);
    printList(head);

    return 0;
}
