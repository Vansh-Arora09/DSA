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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        k%=cnt;
        int first = cnt-k;
        ListNode* curr=head;
        for(int i=1;i<first;i++){
            curr=curr->next;
        }
        ListNode* newList = curr->next;
        curr->next=NULL;
        ListNode* fir = reverse(head);
        ListNode* sec = reverse(newList);
        ListNode* fin = fir;
        while(fir->next!=NULL){
            fir=fir->next;
        }
        fir->next=sec;
        ListNode* res = reverse(fin);
        return res;
    }
};