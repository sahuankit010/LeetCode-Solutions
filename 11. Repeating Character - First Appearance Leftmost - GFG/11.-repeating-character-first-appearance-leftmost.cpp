// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
    int firstIndex[256]; 
    for (int i = 0; i <256; i++) 
        firstIndex[i] = -1; 
  
    // Traverse from left and update result 
    // if we see a repeating character whose 
    // first index is smaller than current 
    // result. 
    int res = INT_MAX; 
    for (int i = 0; i < s.length(); i++) { 
        if (firstIndex[s[i]] == -1) 
           firstIndex[s[i]] = i; 
        else
           res = min(res, firstIndex[s[i]]); 
    } 
  
    return (res == INT_MAX) ? -1 : res; 
    } 
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends