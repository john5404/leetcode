// LeetCode - 21 Merge Two Sorted Lists

#include "stdio.h"
#include <stdlib.h>
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->val > list2->val)
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    else
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
}

void traverse(struct ListNode *list1)
{
    while (list1 != NULL)
    {
        printf("%d ", list1->val);
        list1 = list1->next;
    }
    printf("\n");
}

struct ListNode *new (int value)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = value;
    temp->next = NULL;
    return temp;
}

void main()
{
    struct ListNode *merageList;
    struct ListNode *list1_1 = new (1);
    struct ListNode *list1_2 = new (2);
    struct ListNode *list1_3 = new (4);
    list1_1->next = list1_2;
    list1_2->next = list1_3;
    list1_3->next = NULL;

    struct ListNode *list2_1 = new (1);
    struct ListNode *list2_2 = new (3);
    struct ListNode *list2_3 = new (4);
    list2_1->next = list2_2;
    list2_2->next = list2_3;
    list2_3->next = NULL;

    merageList = mergeTwoLists(list1_1, list2_1);
    traverse(merageList);
}