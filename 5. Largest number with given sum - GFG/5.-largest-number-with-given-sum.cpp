// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        long long ans=0;
        string str="";
       if(sum==0 and n!=0) return "0";
       
       while(n>0){
           for(int i=9;i>0;i--){
               if(sum-i>=0){
                   char c=i+'0';
                   str+=c;
                   sum-=i;
                   break;
               }
           }
           n--;
           if(sum<=0) break;
       }
      if(n<=0 and sum>0) return "-1";
       if(n!=0){
           while(n>0){
               str+='0';
               n--;
           }
       }
       
       return str;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends