class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,vector<int>>ump;
        int n=wordsDict.size();
        int id1=-1, id2=-1;
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(wordsDict[i]==word1){
                id1 = i;
            }
            else if(wordsDict[i]==word2){
                id2=i;
            }
            
            if(id1!=-1 && id2!=-1){
                ans = min(ans, abs(id1-id2));
            }
        }
        return ans;
        
    }
};