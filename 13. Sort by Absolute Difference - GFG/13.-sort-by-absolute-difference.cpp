// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    // static bool myComp(int a, int b)
    public:
    
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    void sortABS(int a[],int n, int k)
    {
       //Your code here
       
       int b[n];
       vector<pair<int,int>>ans(n);
       for(int i=0;i<n;i++)
       {
           b[i]=a[i];
           ans[i].first=abs(k-a[i]);
           ans[i].second=i;
       }
       sort(ans.begin(),ans.end());
       for(int i=0;i<n;i++)
       {
           a[i]=b[ans[i].second];
       }
    }

};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends