class MyHashSet {
    int [] hash = new int[1000001];
    public MyHashSet() {
        
    }
    
    public void add(int key) {
        hash[key] = 1;
    }
    
    public void remove(int key) {
        if(hash[key] == 1) hash[key] = 0;
    }
    
    public boolean contains(int key) {
        return hash[key] == 1;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */