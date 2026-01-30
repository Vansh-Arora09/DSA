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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode* dummy = res;
        int carry=0;
        while(l1 || l2){
            int num1 = (l1!=NULL ? l1->val : 0);
            int num2 = (l2!=NULL ? l2->val : 0);
            ListNode* sum = new ListNode((num1+num2+carry)%10);
            res->next = sum;
            res = res->next;
            carry = (num1+num2+carry)/10;

            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next; 
        }
        if(carry!=0){
            ListNode *last = new ListNode(carry);
            res->next = last;
            res = res->next;
        }
        return dummy->next;
    }
};