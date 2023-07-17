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
        ListNode* result = new ListNode();
        ListNode* current = result;
        int sum = 0, carry = 0;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            sum = l1->val + carry;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            sum = l2->val + carry;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            l2 = l2->next;
        }
        if(carry){
            current->next = new ListNode(carry);
            current = current->next;
        }
        return result->next;
    }
};