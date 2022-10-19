class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string tmp;
            for(int i = 0; i < s.size(); i += k){
                string str = s.substr(i , k);
                int sum = 0;
                for(char c : str){
                    sum += c - '0';
                }
                tmp += to_string(sum);    
            }
            s = tmp;
        }
        return s;
    }
};