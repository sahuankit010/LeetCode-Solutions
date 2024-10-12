class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string answer = "";
        for(const string &str: strs){
            int size = str.size();
            answer += to_string(size) + '#' + str;
        }
        cout<<answer<<endl;
        return answer;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;

        int i=0;

        int n =s.size();

        while(i<n){

            int j = i;

            while(s[j] != '#'){
                j++;
            }

            int size = stoi(s.substr(i, j-i));

            j++;

            strs.push_back(s.substr(j, size));
            
            i = j+size;

        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));