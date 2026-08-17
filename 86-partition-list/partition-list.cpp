
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;
        
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }
        
        greaterTail->next = nullptr; // terminate the list, avoid cycles
        lessTail->next = greaterDummy.next; // connect the two partitions
        
        return lessDummy.next;
    }
};