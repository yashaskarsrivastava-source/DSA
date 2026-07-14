
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // Find length and tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        // Make it circular
        tail->next = head;
        
        // Find new tail: (length - k - 1) steps from head
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};