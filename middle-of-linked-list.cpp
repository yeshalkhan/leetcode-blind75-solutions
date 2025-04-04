class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next)  // to get the second middle in case linked list has even length
            slow = slow->next;
        return slow;
    }
};
