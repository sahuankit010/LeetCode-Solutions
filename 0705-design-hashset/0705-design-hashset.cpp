class MyHashSet {
public:
    vector<int>hash;
    MyHashSet() {
        hash.resize(1000001,0);
    }
    
    void add(int key) {
        hash[key]=1;
    }
    
    void remove(int key) {
        if(hash[key]==1){
            hash[key]=0;
        }
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */