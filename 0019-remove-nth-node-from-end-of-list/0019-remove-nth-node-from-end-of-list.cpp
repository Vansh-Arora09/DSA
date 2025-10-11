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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(n==count){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp = head;
        for(int i=1;i<count-n;i++){
            temp=temp->next;
        }
        ListNode* to_del = temp->next;
        temp->next = temp->next->next;
        delete to_del;
        return head;
    }
};