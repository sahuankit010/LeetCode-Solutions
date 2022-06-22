// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.second<p2.second;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meet;
        
        for(int i = 0;i<n;i++){
            meet.push_back({start[i],end[i]});
        }
        
        sort(meet.begin(), meet.end(), cmp);
        
        int ans=1;
        pair<int,int> p;
        p = make_pair(meet[0].first, meet[0].second);
        
        for(int i=1;i<meet.size();i++){
            if(p.second<meet[i].first){
                p = make_pair(meet[i].first, meet[i].second);
                ans++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends