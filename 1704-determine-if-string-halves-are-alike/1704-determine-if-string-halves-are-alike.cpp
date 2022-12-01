class Solution {
public:
    int count(string str){
        int res=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='a' or str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
                res++;
        }
        return res;
    }
    bool halvesAreAlike(string s) {
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int n= s.size();
        
        string a = s.substr(0, n/2);
        string b = s.substr(n/2, n/2);
        // cout<<a<<" "<<b;
        int c1 = count(a), c2 = count(b);
        return c1==c2;
    }
};