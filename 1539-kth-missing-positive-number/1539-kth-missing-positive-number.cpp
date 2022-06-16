class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<int,int>mp;
        
        for(int i =0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int count =0;
        
        for(int i = 1 ;count!=k;i++){
            if(mp.find(i)==mp.end()){
                count++;
            }
            
            if(count == k) return i;
        }
        return 1;
    }
};