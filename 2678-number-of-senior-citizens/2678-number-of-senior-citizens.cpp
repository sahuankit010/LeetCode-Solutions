class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(const string &str : details){
            string st = str.substr(11, 2);
            int age = stoi(st);
            if(age > 60) ++ans;
        }
        return ans;
    }
};