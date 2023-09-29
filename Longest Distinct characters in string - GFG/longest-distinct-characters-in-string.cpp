//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n = s.size();
    unordered_set<char> uset;
    int ans = 0;
    int left = 0;
    for(int i=0; i<n; i++){
        while (uset.count(s[i])) {
            // If the current character already exists in the set,
            // remove characters from the left of the window until
            // the current character becomes distinct.
            uset.erase(s[left]);
            left++;
        }

        // Add the current character to the set
        uset.insert(s[i]);

        // Update the answer with the length of the current substring
        ans = max(ans, i - left + 1);
    }
    // int temp = uset.size();
    return ans;
    
}