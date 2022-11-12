class MedianFinder {
public:
    
    priority_queue<int> maxpq; // Max heap->entering more elements normally if sizes are equal
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        if(maxpq.empty() || maxpq.top() > x) {
            maxpq.push(x);
        }
        else {
            minpq.push(x);
        }
        balanceHeaps();
    }
    void balanceHeaps(){
        if(maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(maxpq.size() == minpq.size())
            return (minpq.top() + maxpq.top()) / 2.0;
        else 
            return (maxpq.size() > minpq.size())? (double) maxpq.top() : (double) minpq.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */