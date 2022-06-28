// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m){
        // code here
        int begin1=0, end1=n;
        while(begin1<=end1){
            
            int i1 = (begin1+end1)/2;
            int i2=(n+m+1)/2-i1;
            
            int min1=(i1==n)? INT_MAX:arr[i1];
            int max1=(i1==0)? INT_MIN:arr[i1-1];
            
            int min2 = (i2==m)? INT_MAX:brr[i2];
            int max2 = (i2==0)? INT_MIN: brr[i2-1];
            
            if((max1<=min2) and (max2<=min1)){
                if((n+m)%2==0)
                    return (max(max1,max2)+min(min1,min2))/2;
                else
                    return max(max1,max2);
            } else if(max1>min2) end1 = i1 - 1;
            else begin1 = i1+1;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends