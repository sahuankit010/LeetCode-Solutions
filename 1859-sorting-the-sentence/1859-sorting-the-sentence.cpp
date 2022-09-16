class Solution {
public:
    string sortSentence(string s) {
        map<int,string> mp;
        int lastSp = -1;
        for(int i=0;i<s.size(); i++){
            if(s[i]==' ') lastSp = i;
            else if(s[i]>=49 && s[i]<=57){
                if(lastSp==-1){
                    mp[s[i]]= s.substr(0,i);
                } else{
                    mp[s[i]] = s.substr(lastSp+1, i-lastSp-1);
                }
            }
        }
        string ans ="";
        for(auto x: mp){
            ans.append(x.second);
            ans += " ";
        }
        
        string temp = ans.substr(0, ans.size()-1);
        return temp;
    }
};