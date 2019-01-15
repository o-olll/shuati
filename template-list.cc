#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "list.h"
#include "utils.h"

using namespace std;


int main(int argc, char** argv)
{
    vector<int> test_case = {1,2,3,4,5,6};
    ListNode* head = generateList(test_case.begin(), test_case.end());
    printList(head);

    return 0;
}
