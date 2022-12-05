class Solution {
public:
    
    void store(string str, unordered_set<char> &us){
        for(char c: str) us.insert(c);
    }
    vector<string> findWords(vector<string>& words) {
        string first = "qwertyuiop", second = "asdfghjkl", third =  "zxcvbnm";
        
        unordered_set<char> us1, us2, us3;
        
        store(first, us1);
        store(second, us2);
        store(third, us3);
        
        vector<string>ans;
        for(string str : words){
            unordered_set<int> temp;
            string res = str;
            transform(begin(str), end(str), begin(str), ::tolower);
            for(char c: str){
                if(us1.find(c)!=us1.end()){
                    temp.insert(1);
                } else if(us2.find(c)!=us2.end()){
                    temp.insert(2);
                } else {
                    temp.insert(3);
                }
            }
            if(temp.size()==1){
                ans.push_back(res);
            }
        }
        return ans;
    }
};