class Solution {
public:
    
    static bool comp(pair<int,int>p1, pair<int,int> p2){
        if(p1.second>p2.second) return true;
        if(p1.second==p2.second) return p1.first>p2.first;
        return false;
    }
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>ump;
        for(int x: arr){
            ump[x]++;
        }
        
        vector<pair<int,int>>temp;
        
        for(auto x: ump){
            if(x.first == x.second)
                temp.push_back({x.first, x.second});
        }
        if(!temp.size()) return -1;
        if(temp.size()==1) return temp[0].first;
        sort(temp.begin(), temp.end(), comp);
        
        return temp[0].first;
    }
};