#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

template<class BidirIt>
ListNode* generateList(BidirIt start, BidirIt last)
{
    if (start == last--) {
        return NULL;
    }

    ListNode *head = NULL, *current = NULL;
    do {
        current = new ListNode(*last);
        current->next = head;
        head = current;
    } while (start != last--);

    return head;
}

void printList(ListNode *head);
