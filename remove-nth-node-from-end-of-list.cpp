class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        } 
        if (fast == NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            return head;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        temp = NULL;
        return head;
    }
};
