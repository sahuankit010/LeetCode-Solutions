class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = INT_MIN;
        for(int i=0;i<sentences.size(); i++){
            cout<<sentences[i] << endl;
        }
        for(int i=0;i<sentences.size(); i++){
            int countSpace = 0;
            for(int j=0; j<sentences[i].size(); j++){
                if(sentences[i][j] == ' ') countSpace++;
            }
            res = max(res, countSpace);
        }
        
        return res+1;
    }
};