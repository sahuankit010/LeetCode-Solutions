// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size()!=str2.size()) return false;
        unordered_map<char,char> h;
        h[str1[0]]=str2[0];
        for(int i=1;i<str1.size();i++){
            if(h.find(str1[i])==h.end()){
                h[str1[i]]=str2[i];
            } else if(h[str1[i]]!=str2[i]) return false;
        }
        unordered_map<char,char> h1;
        h1[str2[0]]=str1[0];
        for(int i=1;i<str1.size();i++){
            if(h1.find(str2[i])==h1.end()){
                h1[str2[i]]=str1[i];
            } else if(h1[str2[i]]!=str1[i]) return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends