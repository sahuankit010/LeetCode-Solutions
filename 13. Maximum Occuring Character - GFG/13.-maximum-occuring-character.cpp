// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        char ans;
        int mini = 0;
        int arr[26]={0};
        for(int i=0;i<str.size();i++) arr[str[i]-97]++;
        for(int i=0;i<str.size();i++){
            if(arr[str[i]-97]>mini){
                mini = arr[str[i]-97];
                ans=str[i];
            } else if(mini==arr[str[i]-97]) {
                ans = min(str[i],ans);
            }
        }
        return ans;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends