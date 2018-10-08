#include <vector>
#include <iterator>
#include <iostream>
#include "list.h"

void printList(ListNode *head)
{
    while (head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
