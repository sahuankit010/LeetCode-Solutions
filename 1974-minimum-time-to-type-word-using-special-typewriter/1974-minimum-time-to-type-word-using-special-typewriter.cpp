class Solution {
public:
    int minTimeToType(string word) {
        int ans=0, dist = 0;
        char current = 'a';
        for(int i=0;i<word.length();i++){
            if(word[i]!=current){
                
                dist = abs((int)(word[i]-current));
                if(dist>13) dist = 26 - dist;
            } else{
                dist = 0;
            }
            ans+=1+dist;
            current = word[i];
        }
        
        return ans;
    }
};