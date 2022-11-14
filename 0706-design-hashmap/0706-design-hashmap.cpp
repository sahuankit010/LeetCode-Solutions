// #include<vector>
class MyHashMap {
public:
      int vec[10000001]={-1};
    MyHashMap() {
        // vec.resize(1000000);
        for(int i=0; i<=1000000; i++){
            vec[i]=-1;
        }
    }
    
    void put(int key, int value) {
            vec[key]=value;
    }
    
    int get(int key) {
        return vec[key];
    }
    
    void remove(int key) {
        vec[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */