class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }

    void update(int key){
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        update(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key].second = value;
            update(key);
        }else{
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            cap--;
        }

        if(cap < 0){
            cache.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */