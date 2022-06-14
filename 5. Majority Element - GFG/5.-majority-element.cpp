// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        
        //Moore Voting Algorithm
        
        //Finding the candidate element
        int count = 1, res = 0;
        for(int i=1;i<size;i++){
            if(a[i]==a[res]) count++;
            else count--;
            if(count==0){
                res = i;
                count = 1;
            }
        }
        
        //Checking
        count = 0;
        for(int i=0;i<size;i++){
            if(a[i]==a[res]) count++;
            
        }
        return count>size/2? a[res]: -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends