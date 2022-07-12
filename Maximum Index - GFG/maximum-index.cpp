// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int n) 
    { 
        // Your code here
        int left[n],right[n];
        int mini = left[0] = A[0];
        int maxi = right[n-1] = A[n-1];
        
        for(int i=1;i<n;i++){
            if(A[i]<mini) mini=A[i];
            left[i]=mini;
        }
        
        for(int i=n-2;i>=0;i--){
            if(A[i]>maxi) maxi = A[i];
            right[i]=maxi;
        }
        
        int maxDiff = INT_MIN, i=0,j=0;
        while(i<n and j<n){
            if(left[i]<=right[j]){
                maxDiff = max(maxDiff,j-i);
                j++;
            } else i++;
        }
        return maxDiff;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends