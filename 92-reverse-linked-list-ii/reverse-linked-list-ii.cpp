/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Move prev to the node just before position 'left'
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        
        // 'curr' is the first node to be reversed (position 'left')
        ListNode* curr = prev->next;
        
        // Repeatedly take the node right after curr and move it to right after prev
        for (int i = 0; i < right - left; i++) {
            ListNode* toMove = curr->next;
            curr->next = toMove->next;
            toMove->next = prev->next;
            prev->next = toMove;
        }
        
        return dummy.next;
    }
};