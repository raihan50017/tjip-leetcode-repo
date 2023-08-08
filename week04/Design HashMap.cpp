class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int H = createHash(key);
        auto node = new Node(key,value,_mapping[H]);
        node->_next = _mapping[H];
        _mapping[H] = node;
    }
    
    int get(int key) {
        int H = createHash(key);
        auto node = _mapping[H];
        while(node){
            if(node->_key==key){
                return node->_value;
            }
            node = node->_next;
        }
        return -1;
    }
    
    void remove(int key) {
        int H = createHash(key);
        auto node = _mapping[H];
        if(node==nullptr){
            return;
        }
        if(node->_key==key){
            _mapping[H]=node->_next;
            delete node;
            return;
        }
        while(node && node->_next){
            if(node->_next->_key==key){
                auto temp = node->_next;
                node->_next=node->_next->_next;
                delete temp;
            }
            node = node->_next;
        }
    }
private:
    const static int CAPACITY = 19;
    const static int BASE = 12;
    const static int OFFSET = 23;
    class Node{
        public:
        int _key, _value;
        Node* _next;
        Node(int key, int value, Node* next){
            _key = key;
            _value = value;
            _next = next;
        }
    };
    Node* _mapping[CAPACITY]={};
    int createHash(int key){
        return ((key*BASE)+OFFSET)%CAPACITY;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */