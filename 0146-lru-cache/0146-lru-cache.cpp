class LRUCache {
public:
    list<int> dll; // key
    map<int, pair<list<int>::iterator, int>> map; // key, {address, val}
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }

    void makeUpdated(int key){
        dll.erase(map[key].first);
        dll.push_front(key);
        map[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!map.count(key)){
            return -1;
        }

        makeUpdated(key);
        return map[key].second;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key].second = value;
            makeUpdated(key);
        } else {
            dll.push_front(key);
            map[key].second = value;
            map[key].first = dll.begin();
            n--;
        }

        if(n < 0){
            map.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */