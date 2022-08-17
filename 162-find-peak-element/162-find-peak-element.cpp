class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        if(n==1 || arr[0]>arr[1]) //For Base Case and Border Condition
            return 0;
        if(arr[n-1]>arr[n-2]) //Border Condition
            return n-1;
        
        int low = 0, high = n-1;
        int mid;
        int a=-1;
        while(low<=high){
            mid  = low + (high-low)/2;
            
            if((mid-1>=0 && arr[mid]>arr[mid-1]) &&  
                        ((mid-1)<n && arr[mid]>arr[mid+1])) return a = mid;
               
              if(arr[mid+1]>arr[mid]) low=mid+1;
              else high=mid-1; 
        }
        return mid;
    }
};