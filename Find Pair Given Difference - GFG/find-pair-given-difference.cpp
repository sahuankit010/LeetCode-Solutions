//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int diff){
    //code
    unordered_map<int,int>ump;
    for(int i=0;i<n; i++)
        ump[arr[i]]++;
    
    for(int i=0; i<n; i++){
        if(ump[arr[i]]==1) ump.erase(arr[i]);
        else ump[arr[i]]--;
        if(ump.find(abs(diff-arr[i]))!=ump.end()) return true;
        ump[arr[i]]++;
    }
    return false;
}