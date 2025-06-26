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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag=true;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow=slow->next;
        ListNode* prev = NULL;
        ListNode* after = NULL;
        while(slow!=NULL){
            after = slow->next;
            slow->next= prev;
            prev=slow;
            slow=after;
        }
        ListNode* rev1 = prev;
        while(rev1!=NULL && temp!=NULL){
            if(rev1->val!=temp->val){
                flag=false;
            }
            rev1=rev1->next;
            temp=temp->next;
        }
        return flag;
        
    }
};