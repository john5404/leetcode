// 83. Remove Duplicates from Sorted List
#include "stdio.h"
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *temp;

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    if (head->val == head->next->val)
    {
        temp = head->next->next;
        head->next = temp;
        head = deleteDuplicates(head);
    }
    else
        head->next = deleteDuplicates(head->next);

    return head;
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
    struct ListNode *list;
    struct ListNode *list_1 = new (1);
    struct ListNode *list_2 = new (1);
    struct ListNode *list_3 = new (1);
    struct ListNode *list_4 = new (3);
    struct ListNode *list_5 = new (3);
    struct ListNode *list_6 = new (5);
    list_1->next = list_2;
    list_2->next = list_3;
    list_3->next = list_4;
    list_4->next = list_5;
    list_5->next = list_6;
    list_6->next = NULL;
    printf("A\n");
    list = deleteDuplicates(list_1);
    printf("B\n");
    traverse(list);
}