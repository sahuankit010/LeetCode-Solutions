class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int sz = words.size();
        vector<string> ans;
        unordered_map<char, array<int,100>> mp;
         
        for(int i=0;i<sz;i++)  {
            for(int j=0;j<words[i].size();j++)      //get each letter in word
                mp[words[i][j]][i]++;               //increment the count at appropriate index in map
        }
        int cnt=0;      //count variable to keep minimum occurence count of a letter in each word
        for(auto x:mp){
            cnt = INT_MAX;
            for(int i=0;i<sz;i++){
                if(x.second[i]< cnt)
                    cnt = x.second[i];      //get the minimum common occurence
            }
            string s(1, x.first);
            for(int i=0;i<cnt;i++)
                ans.push_back(s);           //push to the answer vector 'count' times
        }
        return ans;
    }

};