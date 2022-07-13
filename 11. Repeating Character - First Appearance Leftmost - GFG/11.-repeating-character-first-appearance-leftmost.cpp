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
        //Your code here
        if(s.length()<2) return -1;
        int mini=INT_MAX;
        for(int i=1;i<s.length();i++){
            int curr=INT_MAX;
            for(int j=0;j<i;j++){
                if(s[i]==s[j]){
                    curr=min(j,curr);
                    break;
                }
            }
            mini=min(mini,curr);
        }
        return mini==INT_MAX? -1 : mini ;
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