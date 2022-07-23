class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int>h;
        int count=0;
        for(int i=0;i<arr.size();i++) h[arr[i]]++;
        
        for(auto x: arr){
            if(h.find(x+1)!=h.end())
                count++;
        }
        
        return count;
    }
};