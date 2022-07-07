// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

 // } Driver Code Ends
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c) 
    { 
        //Your code here
        vector<int>ans;
        int i=0,j=0,k=0;
        while(i<a.size() and j<b.size() and k<c.size()){
            if(a[i]<=b[j] and a[i]<=c[k]){
                ans.push_back(a[i++]);
            } else if(b[j]<=a[i] and b[j]<=c[k]){
                ans.push_back(b[j++]);
            } else{
                ans.push_back(c[k++]);
            }
        }
        
        if(i==a.size()){
            while(j<b.size() and k<c.size()){
                            if(b[j]<=c[k]){
                ans.push_back(b[j++]);
            }else{
                ans.push_back(c[k++]);
            }
            }

        }
        
        if(j==b.size()){
            while(i<a.size() and k<c.size()){
                            if(a[i]<=c[k]){
                ans.push_back(a[i++]);
            }else{
                ans.push_back(c[k++]);
            }
            }

        }
        
        if(k==c.size()){
            while(i<a.size() and j<b.size()){
                if(b[j]<=a[i]){
                ans.push_back(b[j++]);
            }else{
                ans.push_back(a[i++]);
            }
            }
        }
        
        if(i<a.size()){
            for(int q=i;q<a.size();q++) ans.push_back(a[q]);
        }
        
        if(j<b.size()){
            for(int q=j;q<b.size();q++) ans.push_back(b[q]);
        }
        if(k<c.size()){
            for(int q=k;q<c.size();q++) ans.push_back(c[q]);
        }
        return ans;
    } 

};

// { Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

    Solution obj;
    vector<int>ans = obj.mergeThree(A, B, C);
    for(auto i: ans)cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 
  // } Driver Code Ends