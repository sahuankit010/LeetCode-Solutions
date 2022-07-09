// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool myComp(pair<int,int>p1,pair<int,int>p2){
        if(p1.second>p2.second) return true;
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return false;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int>ans;
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++) ump[arr[i]]++;
        vector<pair<int,int>>vec;
        
        for(auto x:ump){
            vec.push_back({x.first,x.second});
        }
        sort(vec.begin(),vec.end(),myComp);
        
        for(int i=0;i<vec.size();i++){
            while(vec[i].second--){
                ans.push_back(vec[i].first);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends