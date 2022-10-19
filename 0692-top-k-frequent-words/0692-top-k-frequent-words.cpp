class Solution {
public:
    static bool cmp(pair<int,string>p1, pair<int,string>p2){
        if(p1.first>p2.first) return true;
        if(p1.first==p2.first) return p1.second<p2.second;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        unordered_map<string, int>mp;
        
        for(int i = 0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        vector<pair<int,string>>temp;
        
        for(auto x: mp){
            temp.push_back(make_pair(x.second, x.first));
        }

        sort(temp.begin(), temp.end(),cmp);
                for(int i=0; i<temp.size(); i++){
            cout<<temp[i].first<<" "<<temp[i].second<<endl;
        }
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        // sort(ans.begin(),ans.end(), cmp);
        return ans;
    }
};