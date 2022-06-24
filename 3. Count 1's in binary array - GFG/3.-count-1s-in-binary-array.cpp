// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // n: size of input array
    int countOnes(int arr[], int n)
    {
        
        // Your code here
        int l=0, h=n-1;
        
        while(l<=h){
            
            int mid = l+(h-l)/2;
            if(arr[mid] == 1 and mid == n-1) return n;
            if(arr[mid] == 1 and arr[mid+1]==0){
                if(mid == 0) return 1;
                else return (mid+1);
            }
            else if(arr[mid] ==0){
                h = mid - 1;
            } else{
                l= mid + 1;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends