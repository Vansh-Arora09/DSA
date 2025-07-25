/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }; */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==nullptr){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast = head;
        
        while(fast->next->next!=NULL && fast->next->next->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* back = slow->next;
        slow->next = slow->next->next;
        delete back;
        
        return head;
    }
};