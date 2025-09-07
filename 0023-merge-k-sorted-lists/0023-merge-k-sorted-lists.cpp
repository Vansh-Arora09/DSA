
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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next = merge(l2->next,l1);
            return l2;
        }
    }
    ListNode* mergeLists(vector<ListNode*>&lists, int low,int high){
        if(low==high) return lists[low];
        if(low>high) return nullptr;
        int mid = low+(high-low)/2;
        ListNode* l1 = mergeLists(lists,low,mid);
        ListNode* l2 = mergeLists(lists,mid+1,high);
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists,0,lists.size()-1);
    }
};