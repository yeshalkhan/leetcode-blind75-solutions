class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode* head = new ListNode(-1);
        ListNode* sorted = head;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {  
                sorted->next = list1;
                list1 = list1->next;
            }
            else
            {
                sorted->next = list2;
                list2 = list2->next;
            }
            sorted = sorted->next;
        }
        if (list1)
        {    
            sorted->next = list1;
        }
        else
        {    
            sorted->next = list2;
        }
        
        return head->next;
    }
};
