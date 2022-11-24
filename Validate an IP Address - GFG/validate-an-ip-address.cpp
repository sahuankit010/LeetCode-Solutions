//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            if(s[0]<'0' || s[0]>'9') return 0;
            
            int dot = 0;
            
            int n=s.size();
            
            for(int i=0; i<n; ){
                if((s[i]<'0' || s[i]>'9') && s[i]!='.') return false;
                int j=i;
                string temp = ""; 
                while(s[j]>='0' and s[j]<='9'){
                    if((s[j]<'0' || s[j]>'9') && s[j]!='.') return false;
                    // cout<<s[j]<<" ";
                    temp += s[j++];
                }
                if((s[i]<'0' || s[i]>'9') && s[i]!='.') return false;
                if(i<n-1)
                    if(s[i]=='.' and s[i+1]=='.') return false;
                i=j;
                if(temp[0]=='0' and temp.size()>1) return false;
                if(temp.size()>3) return false;
                int t = stoi(temp);
                
                if(t>255) return false;
                
                if(s[i]=='.') dot++;
                i++;
                if(dot>3) return false;
            }
            
            if(dot!=3) return false;
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends