/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        Node* cpyHead = new Node(head->val);
        auto cpyCurrent = cpyHead;
        auto current = head->next;
        map<Node*, Node*>M;
        int i;
        M[head] = cpyCurrent;
        while(current){
            cpyCurrent->next = new Node(current->val);
            cpyCurrent = cpyCurrent->next;
            M[current] = cpyCurrent;
            current = current->next;
        }
        cpyCurrent = cpyHead;
        current = head;
        while(cpyCurrent && current){
            if(M.count(current->random)){
                cpyCurrent->random = M[current->random];
            }
            else{
                cpyCurrent->random = NULL;
            }
            cpyCurrent = cpyCurrent->next;
            current = current->next;
        }
        return cpyHead;
    }
};