class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        for(int x: arr) mp[x]++;
        
        vector<pair<int,int>> vec;
        
        for(auto x: mp){
            vec.push_back({x.second,x.first});
        }
        
        sort(vec.rbegin(), vec.rend());
        
        // for(int i=0;i<vec.size();i++){
        //     cout<< vec[i].first<<" "<<vec[i].second<<endl;
        // }
        
        int n = arr.size()/2;
        int sum=0, count=0;
        for(auto x: vec){
            sum+=x.first;
            count++;
            if(sum>=n) return count;
        }
        
        return -1;
    }
};