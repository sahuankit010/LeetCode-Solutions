class Solution {
public:
    // static bool cmp(pair<int, int> p1, pair<int, int> p2){
    //     return (p1.second>=p2.second);
    // } 
    int totalFruit(vector<int>& fruits) {
        
        int ans = 0, n=fruits.size();;
        int left = 0, right = 0;
        unordered_map<int,int> ump;
        for(; right<n; right++){
            ump[fruits[right]]++;
            
            if(ump.size()>2){
                ump[fruits[left]]--;
                
                if(ump[fruits[left]] == 0) ump.erase(fruits[left]);
                left++;
            }
        }
        
        return right - left;
    }
};