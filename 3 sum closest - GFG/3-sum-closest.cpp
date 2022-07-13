// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        // code here
        sort(a,a+n);
        int ans = 10000000;

        for(int i=0;i<n-2;i++){
            
            int left = i+1, right = n-1;
            
            while(left<right){
                
                int curr_sum = a[i]+a[left]+a[right];
                
                if(curr_sum==x) return curr_sum;
                
                else if(abs(x-curr_sum)<abs(x-ans)){
                    ans = curr_sum;
                }
                
                if(curr_sum<x) left++;
                else right--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends