#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "list.h"
#include "utils.h"

using namespace std;

ListNode* reverseList(ListNode* head)
{
    ListNode *p, *last;
    for (p=head, last=NULL; p!=NULL;) {
        head = p;
        p = p->next;
        head->next = last;
        last = head;
    }
    return head;
}

int main(int argc, char** argv)
{
    vector<int> test_case = {1};
    ListNode* head = generateList(test_case.begin(), test_case.end());
    printList(head);

    head = reverseList(head);
    printList(head);

    return 0;
}
