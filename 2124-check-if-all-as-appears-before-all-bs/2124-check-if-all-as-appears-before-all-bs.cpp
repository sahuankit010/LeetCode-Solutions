class Solution {
public:
    bool checkString(string s) {
        
        priority_queue<int> pqmax;
        priority_queue<int, vector<int>, greater<int>> pqmin;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'){
                pqmax.push(i);
            } else pqmin.push(i);
        }
        if(!pqmin.size() || !pqmax.size()) return true;  
        return pqmax.top()<pqmin.top();
    }
};