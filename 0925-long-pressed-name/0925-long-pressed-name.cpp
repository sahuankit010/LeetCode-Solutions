class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // unordered_map<char,int> ump1, ump2;
        int n=name.size();
        int m=typed.size();
        
        if(n>m) return false;
        
        // for(int i=0,j=0; i<n && j<m; ){
        //     if(typed[j]!=name[i]) return false;
        //     while(typed[j]==name[i]){
        //         j++;
        //     }
        //     i++;
        //     // if
        // }
        
        int i=0, j=0;
        
        while(i<n && j<m){
            int e=i, f=j;
            int c=0, d=0;
            if(typed[j]!=name[i]) return false;
            while(name[i]==name[e]) {
                e++;
                c++;
            }
            while(typed[j]==typed[f]){
                f++;
                d++;
            }
            if(d<c) return false;
            // while(typed[j]==name[i]){
            //     j++;
            // }
            i+=c;
            j+=d;
        }
        if(i<n || j<m) return false;
        
        return true;
    }
};