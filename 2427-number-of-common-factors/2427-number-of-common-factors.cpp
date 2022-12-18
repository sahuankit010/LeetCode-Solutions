class Solution {
public:
    int commonFactors(int a, int b) {
        int mini = min(a,b);
        int maxi = max(a,b);
        
        unordered_set<int> hash;
        
        for(int i=1; i<=mini; i++){
            if(mini%i==0) hash.insert(i);
        }
        
        int ans=0;
        
        for(int i=1; i<=maxi; i++){
            if(maxi%i==0){
                if(hash.find(i)!=hash.end()) ans++;
            }
        }
        
        return ans;
    }
};