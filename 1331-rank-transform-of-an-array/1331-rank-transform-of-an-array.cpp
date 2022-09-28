class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        
        unordered_map<int,int>mp;
        
        sort(temp.begin(), temp.end());
       
        int count = 1;
        
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(mp[temp[i]]==0){
                mp[temp[i]]=count;
                count++;
            }
        }
        
        for(int i=0; i<n; i++){
            arr[i] = mp[arr[i]];
        }
        
    return arr;
    }
};