class Solution {
public:
    int maximum69Number (int num) {
        
        string snum = to_string(num);
        
        for(char &c: snum){
            if(c=='6'){
                c='9';
                break;
            }
        }
        return stoi(snum);
    }
};