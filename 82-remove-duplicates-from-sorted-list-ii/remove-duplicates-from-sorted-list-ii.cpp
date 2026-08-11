#include <bits/stdc++.h>
using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // agar curr ka next same value hai, toh yeh ek duplicate block hai
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int dupVal = curr->val;
                // saare same-value nodes skip karo
                while (curr != nullptr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr; // pura block hata do
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};