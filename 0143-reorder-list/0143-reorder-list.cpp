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
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* n_head = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return n_head;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr = head;
        ListNode* new_start = slow->next;
        slow->next=NULL;
        ListNode* rev_head = reverseLL(new_start);

        while(curr && rev_head){
            ListNode* nxtA = curr->next;
            ListNode* nxtR = rev_head->next;
            curr->next = rev_head;
            rev_head->next = nxtA;
            curr = nxtA;
            rev_head = nxtR;
        }
    }
};