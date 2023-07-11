class MyLinkedList {
public:
    class Node{
        public:
        int val;
        Node* next;
        Node(int _val, Node* _next){
            val = _val;
            next = _next;
        }
    };
    int len;
    Node* head = nullptr;
    MyLinkedList() {
        len = 0;
        head = new Node(0, nullptr);
    }
    
    int get(int index) {
        if(index<0 || index>=len){
            return-1;
        }
        Node* current = head->next;
        while(index--){
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>len){
            return;
        }
        Node* current = head;
        while(index--){
            current = current->next;
        }
        Node* temp = new Node(val, nullptr);
        temp->next = current->next;
        current->next = temp;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index >= len){
            return;
        }
        Node* current = head;
        while(index--){
            current = current->next;
        }
        Node *toRemove = current->next;
        current->next = current->next->next;
        delete(toRemove);
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */