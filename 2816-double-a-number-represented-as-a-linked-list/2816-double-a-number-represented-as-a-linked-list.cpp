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
    ListNode* doubleIt(ListNode* head) {
        ListNode* reverse = rev(head);
        int carry=0;
        ListNode* curr = reverse, *prev = nullptr;

        while(curr!=nullptr){
            int value = curr->val*2 + carry;
            curr->val = value % 10;
            if(value>9){
                carry=1;
            }
            else{
                carry=0;
            }
            prev = curr;
            curr = curr->next;
        }
        if(carry!=0){
            ListNode* extra = new ListNode(carry);
            prev->next = extra;
        }
        ListNode* res = rev(reverse);
        return res;
    }

    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr, *curr =head, *next;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};