class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size(), size2 = word2.size();

        string ans = "";

        int i = 0, j=0; // iterators for word1 and word2
        int count = 0;
        while(i<size1 && j<size2){
            if(count % 2 == 0){
                ans += word1[i++];
            }else{
                ans += word2[j++];
            }
            count++;
        }

        (i==size1)? addRemainingString(word2, j, size2, ans):
                    addRemainingString(word1, i, size1, ans);

        return ans;
    }

    private:
        void addRemainingString(string &word, int index, int size, string &ans){
            while(index<size){
                ans+=word[index++];
            }
        }
};