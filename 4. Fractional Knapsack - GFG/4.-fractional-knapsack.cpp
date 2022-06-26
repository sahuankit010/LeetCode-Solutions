// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<pair<int,int>,double> p1,pair<pair<int,int>,double> p2){
        return p1.second>=p2.second;
    }
    double fractionalKnapsack(int W, Item arr[], int n){
        // Your code here
        double ans = 0.0f;
        
        vector<pair<pair<int,int>,double>> vw;
        
        for(int i=0;i<n;i++){
            vw.push_back({{arr[i].value,arr[i].weight},(double)arr[i].value/(double)arr[i].weight});
        }
        
        sort(vw.begin(),vw.end(), cmp);
        int i;
        for(i=0;i<n;i++){
            
            if(W-vw[i].first.second>=0){
                ans+=vw[i].first.first;
                W-=vw[i].first.second;
            } else{
                ans+= vw[i].first.first * ((double)W/(double)vw[i].first.second);
                break;
            }
        }
        
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends