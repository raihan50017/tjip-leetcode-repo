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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(0, lists.size()-1, lists);
    }
    ListNode* helper(int low, int high, vector<ListNode*>& lists){
        if(low>high){
            return NULL;
        }
        if(low==high){
            return lists[low];
        }
        int mid = (low+high)/2;
        auto left = helper(low, mid, lists);
        auto right = helper(mid+1, high, lists);
        return mergeTwoLists(left, right);
    }
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dumyHead = new ListNode(0);
        ListNode* cpy = dumyHead;

        while(list1 && list2){
            if(list1->val < list2->val){
                dumyHead->next = new ListNode(list1->val);
                dumyHead = dumyHead->next;
                list1 = list1->next;
            }
            else{
                dumyHead->next = new ListNode(list2->val);
                dumyHead = dumyHead->next;
                list2 = list2->next;
            }  
        }
        while(list1){
            dumyHead->next = new ListNode(list1->val);
            dumyHead = dumyHead->next;
            list1 = list1->next;
        }
        while(list2){
            dumyHead->next = new ListNode(list2->val);
            dumyHead = dumyHead->next;
            list2 = list2->next;
        }
        return cpy->next;
    }
};