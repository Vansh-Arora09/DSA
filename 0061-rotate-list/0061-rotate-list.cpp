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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        ListNode* curr = head;
        int cnt=1;
        while(curr->next!=NULL){
            curr = curr->next;
            cnt++;
        }
        k%=cnt;

        if(k==0) return head;

        curr->next = head;

        ListNode* ncurr = head;
        for(int i=0;i<cnt-k-1;i++){
            ncurr = ncurr->next;
        }

        ListNode* tmp = ncurr->next;
        ncurr->next = NULL;
        return tmp;
    }
};