// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
        //Your code here
        unordered_map<int,int>h;
        vector<int>vec;
        
        for(int i=0;i<N;i++) h[A1[i]]++;
        
        for(int i=0;i<M;i++){
            if(h.find(A2[i])!=h.end()){
                while(h[A2[i]]--){
                    vec.push_back(A2[i]);
                }
                h.erase(A2[i]);
            }
        }
        vector<int>vec2;
        for(auto x: h){
            while(x.second--){
                vec2.push_back(x.first);
            }
        }
        sort(vec2.begin(),vec2.end());
        for(int x: vec2) vec.push_back(x);
        if(vec.size()!=0) return vec;
        
        sort(A1.begin(),A1.end());
        return A1;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends