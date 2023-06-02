class Solution {
public:
    
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second < p2.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int i: arr){
            mp[i]++;
        }
        
        vector<pair<int,int>> vec;
        
        for(auto p: mp)
            vec.push_back({p.first, p.second});
        
        sort(begin(vec), end(vec), comp);
        
        // for(int k = 0; k<vec.size(); k++){
        //     cout<<vec[k].first<< " "<< vec[k].second<<endl;
        // }
        
        int ans = 0;
        int i=0;
        
        for(; i<vec.size(); i++){
            int second = vec[i].second;
            
            if(k>=second){
                k -= second;
                vec[i].second = 0;
            } else{
                vec[i].second -= k;
                k=0;
                break;
            }
            // if(k == 0) break;
        }
        
        // for(int k = 0; k<vec.size(); k++){
        //     cout<<vec[k].first<< " "<< vec[k].second<<endl;
        // }
        
        for(int j = i; j<vec.size(); j++){
            if(vec[i].second) ans++;
        }
            
        
        return ans;
    }
};