class MovingAverage {
public:
    queue<int>q;
    int s;
    double sum;
    MovingAverage(int size) {
        s= size;
        sum=0.0;
    }
    
    double next(int val) {
        if(q.size()>=s){
           sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */