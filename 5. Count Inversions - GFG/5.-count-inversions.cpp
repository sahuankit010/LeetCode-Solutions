// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long countAndMerge(long long arr[], long long l, long long m,long long r){
        long long n1=m-l+1,n2=r-m;
        long long left[n1],right[n2];
        for(int i=0;i<n1;i++)left[i]=arr[l+i];
        for(int i=0;i<n2;i++)right[i]=arr[m+i+1];
        long long res=0;
        long long k=l,i=0,j=0;
        while(i<n1 and j<n2){
            if(left[i]<=right[j])arr[k++]=left[i++];
            else{
                arr[k++]=right[j++];
                res+=n1-i;
            }
        }
        while(i<n1)arr[k++]=left[i++];
        while(j<n2)arr[k++]=right[j++];
        
        return res;
    }
    long long merge(long long arr[],long long l, long long r){
        long long res = 0;
        if(l<r){
            long long  m = l+(r-l)/2;
            res+=merge(arr,l,m);
            res+=merge(arr,m+1,r);
            res+=countAndMerge(arr,l,m,r);
        }
        return res;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long ans = merge(arr,0,N-1);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends