class LRUCache {
private:
    list<int>lru;
    unordered_map<int,int>k_val;
    unordered_map<int,list<int>::iterator>k_loc;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(k_val.count(key)){
            lru.erase(k_loc[key]);
            lru.push_front(key);
            k_loc[key] = lru.begin();
            return k_val[key]; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lru.size()==cap && k_val.count(key)==0){
            int last_key = lru.back();
            k_val.erase(last_key);
            k_loc.erase(last_key);
            lru.pop_back();
            lru.push_front(key);
            k_loc[key] = lru.begin();
            k_val[key] = value;
        }
        else{
            if(k_val.count(key)){
                lru.erase(k_loc[key]);
            }
            lru.push_front(key);
            k_loc[key] = lru.begin();
            k_val[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */