class Solution {
public:
    
    int gcd(int l1, int l2){
        int mini = min(l1,l2);
        while(mini>0){
            if(l1%mini == 0 && l2%mini == 0) return mini;
            mini--;
        }
        
        return 0;
    }
    string gcdOfStrings(string str1, string str2) {
        
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};