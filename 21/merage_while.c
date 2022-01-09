// LeetCode - 21 Merge Two Sorted Lists
#define NULL ((char *)0)
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode newList;
    struct ListNode *temp = &newList;
    if ((list1 == NULL) && (list2 == NULL))
    {
        return NULL;
    }
    while ((list1 != NULL) && (list2 != NULL))
    {
        if (list1->val > list2->val)
        {
            temp->next = list2;
            list2 = list2->next;
        }
        else
        {
            temp->next = list1;
            list1 = list1->next;
        }
        temp = temp->next;
    }
    if (list1 != NULL)
    {
        temp->next = list1;
    }
    if (list2 != NULL)
    {
        temp->next = list2;
    }
    return newList.next;
}