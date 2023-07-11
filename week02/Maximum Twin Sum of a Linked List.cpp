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
    int pairSum(ListNode* head) {
        auto current = head;
        auto fast = head;
        ListNode* prev = nullptr;
        int length=0, mid, max_sum=0;
        while(current){
            length++;
            current = current->next;
        }
        mid = length/2;
        while(mid--){
            fast = fast->next;
        }
        while(fast){
            auto temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }

        while(head && prev){
            max_sum = max(max_sum, head->val+prev->val);
            head = head->next;
            prev = prev->next;
        }

        return max_sum;
    }
};