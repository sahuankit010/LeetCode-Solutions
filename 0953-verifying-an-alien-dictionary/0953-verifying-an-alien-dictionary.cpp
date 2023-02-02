class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
         int n = words.size();

        unordered_map<char, int> orderMap;
        
        for (int i = 0; i < 26; i++) {
            orderMap[order[i]] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            for (int j = 0; j < w1.size(); j++) {
                if (j == w2.size()) {
                    return false;
                }

                if (w1[j] != w2[j]) {
                    if (orderMap[w1[j]] > orderMap[w2[j]]) {
                        return false;
                    }

                    break;
                }
            }
        }

        return true;
    }
};