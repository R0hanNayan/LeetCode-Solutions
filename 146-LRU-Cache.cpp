class LRUCache {
public:
    list<int> dll;
    int cap;
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void updateCache(int key){
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }

    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        updateCache(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key].second = value;
            updateCache(key);
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