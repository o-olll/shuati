#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "list.h"
#include "utils.h"

using namespace std;

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode *p, *last=NULL, *dummy, *tail1, *tail2;
    int i = 1;

    dummy = new ListNode(0);
    dummy->next = head;
    p = dummy;

    for (i=0; i<m && p!=NULL; ++i) {
        tail1 = p;
        p = p->next;
    }

    tail2 = p;
    for (; i<=n && p!=NULL; ++i) {
        head = p;
        p = p->next;
        head->next = last;
        last = head;
    }

    tail1->next = head;
    tail2->next = p;

    head = dummy->next;
    delete dummy;
    return head;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1,2,3,4,5,6};
    ListNode* head = generateList(test_case.begin(), test_case.end());
    printList(head);

    head = reverseBetween(head, atoi(argv[1]), atoi(argv[2]));
    printList(head);

    return 0;
}
