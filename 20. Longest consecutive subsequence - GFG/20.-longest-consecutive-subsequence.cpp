// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      set<int>s(arr,arr+n);
      vector<int>vec(s.begin(),s.end());
    //   sort(arr,arr+n);
      int res = -1;
      int curr = 1;
      for(int i=1;i<vec.size();i++){
          
          if(vec[i-1]==vec[i]-1) curr++;
          else{
              res=max(res,curr);
              curr=1;
          }
      }
      return max(curr,res);
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends