class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int i: arr){
            mp[i]++;
        }
        
        vector<int> vec;
        
        for(auto p: mp)
            vec.push_back(p.second);
        
        sort(begin(vec), end(vec));
        
        int ans = 0;
        int i=0;
        
        for(; i<vec.size(); i++){
            
            if(k>=vec[i]){
                k -= vec[i];
                vec[i]= 0;
            } else{
                vec[i] -= k;
                k=0;
                break;
            }
        }
        
        for(int j = i; j<vec.size(); j++){
            if(vec[i]) ans++;
        }
            
        
        return ans;
    }
};