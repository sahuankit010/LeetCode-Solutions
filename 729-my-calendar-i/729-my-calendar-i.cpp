class MyCalendar {
    vector<pair<int,int>> vec;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int>p = make_pair(start,end);
        if(vec.empty()){
            vec.push_back(p);
            return true;
        } else{
            for(auto i:vec){
                
                if((start>=i.first && start<i.second) || (end>i.first && end<i.second)
                  ||(start<=i.first && end>=i.second))
                    return false;
            }
            
            vec.push_back(p);
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */